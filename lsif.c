#define _GNU_SOURCE     /* To get defns of NI_MAXSERV and NI_MAXHOST */
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <linux/if_link.h>
#include <linux/limits.h>

int is_it_bridge (const char *dev)
{
    char brpath[PATH_MAX];

    memset(brpath, 0, sizeof(brpath));
    snprintf(brpath, sizeof(brpath)-1, "%s/bridge", dev);

    if (access(brpath, R_OK) == 0)
        return 1;
    return 0;
}

char *get_netdev_type (const char *dev)
{
    char sysdev[PATH_MAX], link[PATH_MAX];
    ssize_t ret;
    if (dev == NULL) return "";

    memset(sysdev, 0, sizeof(sysdev));
    memset(link,   0, sizeof(link));
    snprintf(sysdev, sizeof(sysdev)-1, "%s/%s", "/sys/class/net/", dev);

    //fprintf(stdout, "Device:%s, Cheking readlink for %s\n", name, sysdev);
    ret = readlink(sysdev, link, sizeof(link)-1);
    if (ret == -1) {
        perror("readlink");
        exit(EXIT_FAILURE);
    }

    //printf("%s points to %s\n", sysdev, link);
    if (strstr(link, "virtual") == NULL)
        return "physical";
    else
        return is_it_bridge(sysdev) == 1 ? "bridge  ": "virtual ";
}

int main(int argc, char *argv[])
{
   struct ifaddrs *ifaddr, *ifa;
   int family, s, n;
   char host[NI_MAXHOST];

   if (getifaddrs(&ifaddr) == -1) {
       perror("getifaddrs");
       exit(EXIT_FAILURE);
   }

   /* Walk through linked list, maintaining head pointer so we
      can free list later */

   for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
       if (ifa->ifa_addr == NULL)
           continue;

       family = ifa->ifa_addr->sa_family;

       /* For an AF_INET* interface address, display the address */
      if (family == AF_INET) {
           s = getnameinfo(ifa->ifa_addr,
                   (family == AF_INET) ? sizeof(struct sockaddr_in) :
                                         sizeof(struct sockaddr_in6),
                   host, NI_MAXHOST,
                   NULL, 0, NI_NUMERICHOST);
           if (s != 0) {
               printf("getnameinfo() failed: %s\n", gai_strerror(s));
               exit(EXIT_FAILURE);
           }

            printf("%-8s\t%s\t%s\n", ifa->ifa_name, get_netdev_type(ifa->ifa_name), host);
       }
   }

   freeifaddrs(ifaddr);
   exit(EXIT_SUCCESS);
}

