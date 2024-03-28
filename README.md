# push_swap

## Table of Contents
- [Overview](#overview)
- [Requirements](#requirements)
- [Build](#build)
- [Usage](#usage)
    - [Example](#example)
- [Notes](#notes)
- [Lisence](#lisence)

## Overview

`push_swap` is a educational project about building a program in `C` language taking a list of random numbers as argument. and it will output a list of instructions to be consumed by another program to sort those number in two special stacks.

This is good introductory project for sorting algorithms, not only that it also involves using serveral data structures.

For more informatins. Refer to subject file included in the subject directory.

## Requirements

All you need is a Unix machine (Linux, Macos, Freebsd, ...), C compiler and Make.

## Build

To build the project cd into `src` directory, and run the following command:

```sh
make
```

This is will result in a program called `push_swap`.

## Usage

`push_swap` is intended to be used like this:

```sh
./push_swap <number>*
```

Where `<number>` stands for any integer number. and it takes any number of them.

### Example

The following are some examples of inputs and their coresonding outputs.

input:

```sh
./push_swap 2 3 1
```

output:

```
rra
```

Explanation: the only instruction that was needed to get the input sorted is rotating the stack A by one


## Notes

- The project goes beyond just the `rra` instruction obiously, for complete list of instructions, refer to subject file.
- This implemtation also include a `bonus` recipe. which implemetion the interpreter which consumes the outputed instructions from `push_swap` and checks wheter apply those instructions actually sorts the input.

## Lisence

This project is licensed under MIT license. See the LICENSE file for details.
