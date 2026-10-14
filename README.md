# Systems Programming in C

Small, focused C programs I built while learning systems programming at UC Santa Cruz — memory, pointers, linked lists, stacks, hash tables, and file I/O, all by hand. Every project has the design doc I wrote before coding it and the tests I used to check it.

## What's inside

| Folder | What it is |
|---|---|
| `getting-started` | My first C program — a simple hello, kept for the record |
| `caat-text-filter` | `caat`, a small stream filter in the spirit of `cat` that echoes standard input and doubles every vowel |
| `calculator-and-collatz` | A stack-based calculator that evaluates expressions from files, plus Collatz sequence functions and number utilities |
| `string-and-vector-utils` | A function library for strings and vectors: palindrome checks, suffix tests, string repeat, dot products, and a `reduce` that brings higher-order functions to C |
| `text-editor` | A beginner-friendly text editor built on a linked list of lines — append, insert, and edit text node by node |
| `wordle-game` | My own Wordle in C: guess scoring with correct/wrong-position/miss feedback against a vocabulary file |
| `wordle-solver` | A solver for the Wordle game above — scores letters against the whole vocabulary to suggest strong guesses |
| `business-database` | A small business/customer database using my own hash table implementation in C, with file I/O and a Python companion script |

## Build & run

Each folder has its own `Makefile` (they target `clang`; `gcc` works too with `make CC=gcc`):

```bash
cd wordle-game
make
./wordle_game
```

Test files live next to the code they test (e.g. `hw2_test.c` style drivers became per-folder `*_test.c` files), and example inputs are included where a program reads from a file.

## Why I built this

C is where I learned what the machine is actually doing — that a string is bytes with a terminator, that memory is mine to manage and mine to leak. These projects are small on purpose. Each one isolates a single idea and makes me implement it for real instead of calling a library.

— Abrham Dawit, Computer Engineering, UC Santa Cruz '28
