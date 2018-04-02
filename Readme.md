# lsif : LiSt network InterFaces

Simpler alternative to ifconfig(8) to list all the network devices and
IP addresses, for when you don't want to look at the details of ifconfig.

Simple ifconfig. This can also be used in scripts in a much easier way.

## Getting Started

In order to get started, you can run the lsif(1) from bin/ directory.
That is built for x86_64 architecture and a relatively new Linux distribution.
This was built and tested on Ubuntu 16.04 LTS on x86_64

If not, simple make will build the binary.

Quick and dirty way to get started is as follows
```
 git clone https://github.com/codervijo/lsif.git && cd lsif && ./bin/lsif
```
You may want to adjust you PATH env variable to point to this directory, or copy it to another
directory in your PATH.
 
### Prerequisites

What things you need to install the software and how to install them

```
make
```

### Installing

A step by step series of examples that tell you have to get a development env running

Say what the step will be

```
make help
```

To install

```
make
```

Please test and report bugs, comments and suggestions.

## Running the tests

The automated tests for this system will be added soon.

### Break down into end to end tests

There are no automated tests at the moment

### And coding style tests

To be added

```
Please stay tuned
```

## Deployment

Not supported at the moment

## Built With

* [Gcc](http://gcc.gnu.org/) - Gnu C Compiler
* [Make](https://www.gnu.org/software/make) - Gnu Make

## Contributing

Contributions are welcome, please send PRs.

## Versioning

We use [SemVer](http://semver.org/) for versioning to some extent.
lsif doesn't have a public API yet. But this is what we aim  towards.
Please stay tuned.

## Authors

* **Vijo Cherian** - *Initial work* - [codervijo](https://github.com/codervijo)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Linux Developers
* Colleagues

