# Matrix Operations and Convolution

This project is a C program that performs various matrix operations, including the generation of random matrices, calculation of matrix traces, and 2D convolution. The program allows users to input the size of matrices, generates random matrices with specified sizes, and performs convolution on them. Additionally, it calculates and displays the traces of the input matrices.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The program is designed to showcase basic matrix operations and convolution using C. It provides a simple command-line interface for users to input matrix sizes, generates random matrices, and performs convolution operations. The main focus is to demonstrate the implementation of these mathematical operations in a programming context.

## Features

- Generation of random matrices with specified sizes.
- Calculation and display of matrix traces.
- 2D convolution of matrices.

## Requirements

- A C compiler (e.g., GCC)
- Standard C libraries
  
## Usage

1. Clone the repository to your local machine.
2. Compile the program using a C compiler.
3. Run the executable.
4. Follow the on-screen prompts to input matrix sizes and view the results.

```bash
# Example compilation and execution
$ gcc -o main main.c
$ ./main

## Exemples

# Example input and output
$ ./main
Saisir la taille de A: 3
|  2  | -7  |  4  |
|  1  | -8  | -9  |
|  6  | -3  |  0  |
Trace A = -6

Saisir la taille de B impair entre 1 et 1: 1
|  8  |
Trace B = 8

|  16  | -56  |  32  |
|   8  | -28  |  16  |
|  48  | -24  |   0  |
