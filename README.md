*This project has been created as part of the 42 curriculum by vrouxel, paukowal, dtarasov.*

# Push_swap

## Description

`push_swap` sorts a stack of distinct integers using two stacks (`a` and `b`) and
the restricted Push_swap instruction set. The program receives stack `a` on the
command line, where the first number is the top of the stack, and writes a
newline-separated sequence of operations to standard output. The sequence leaves
the numbers in ascending order in stack `a`.

The project focuses on algorithmic complexity in the Push_swap operation model.
It includes three selectable sorting strategies and an adaptive strategy that
chooses between them from the measured disorder of the input.

The accepted operations are:

| Operation | Effect |
| --- | --- |
| `sa`, `sb` | Swap the top two values of stack `a` or `b` |
| `ss` | Apply `sa` and `sb` |
| `pa`, `pb` | Push the top value from `b` to `a`, or from `a` to `b` |
| `ra`, `rb` | Rotate a stack upwards |
| `rr` | Apply `ra` and `rb` |
| `rra`, `rrb` | Reverse-rotate a stack |
| `rrr` | Apply `rra` and `rrb` |

Invalid input, values outside the `int` range, and duplicate values produce
`Error` followed by a newline on standard error.

## Instructions

### Compilation

The project requires a C compiler and `make`:

```sh
make
```

This builds the `push_swap` executable and its local `libft`, list, and
`ft_printf` libraries. Other available targets are:

```sh
make clean    # Remove object files
make fclean   # Remove object files, libraries, and the executable
make re       # Rebuild from scratch
```

### Execution

Run the default adaptive strategy by passing the integers directly:

```sh
./push_swap 2 1 3 6 5 8
```

The optional strategy flags must appear before the integer arguments:

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

`--adaptive` is the default when no strategy flag is provided. With no
arguments, the program prints nothing and exits successfully.

The optional benchmark mode keeps the operation stream on standard output and
writes diagnostics to standard error:

```sh
./push_swap --bench --adaptive 4 67 3 87 23
./push_swap --bench 4 67 3 87 23 > operations.txt 2> benchmark.txt
```

Benchmark output includes the input disorder percentage, selected strategy and
complexity class, total operations, and the count of every Push_swap operation.

### Checking a result

The project resources include `checker_linux` for Linux systems. Pipe the generated
operations to it using the same input:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

The checker prints `OK` for a correctly sorted stack and `KO` otherwise.

Random sets can be tested the following way:

```sh
shuf -i 0-9999 -n 100 > args.txt ; ./push_swap $(cat args.txt) | wc -l
```
or

```sh
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
```

both test will output the numbers of operations that were performed

## Algorithms and technical choices

### Disorder metric

Before any operation is generated, the program computes disorder as the ratio of
inverted pairs to all possible pairs:

```text
disorder = number of pairs (i, j) where i < j and a[i] > a[j]
           ----------------------------------------------------
                         total number of pairs
```

The value is in the range `[0, 1]`. A sorted stack has disorder `0`; a reverse
sorted stack has disorder `1`. This metric is also reported by `--bench`.

### Small inputs

Inputs of five values or fewer use a dedicated small-input sorter. It handles
two and three values directly and extracts the minimum value(s) for four- and
five-value inputs, then restores them to stack `a`.

### Simple strategy: bubble sort, `O(n^2)`

`--simple` uses a bubble-sort adaptation. It compares adjacent values with
`sa`, advances through the stack with `ra`, and restores the rotation after
each pass with reverse rotations. Each pass reduces the unsorted boundary, and
the algorithm stops early when a pass performs no swap.

This is the baseline strategy: it is straightforward and effective for nearly
sorted inputs, while its worst-case number of generated operations is
quadratic.

### Medium strategy: chunk sorting, `O(n sqrt(n))`

`--medium` divides the normalized ranks into chunks whose size is approximately
`sqrt(n)`. Values in the current rank range are pushed from `a` to `b`; smaller
values within that range are rotated deeper in `b`. The program then finds and
pushes the largest remaining rank back to `a`, keeping the final stack ordered.

There are approximately `sqrt(n)` chunks. Processing the ranges and restoring
the values gives the intended `O(n sqrt(n))` class in generated Push_swap
operations.

### Complex strategy: binary radix sort, `O(n log n)`

`--complex` assigns each value its relative rank, so negative and positive
integers can be sorted without depending on their absolute representation. It
performs stable least-significant-bit passes over those ranks:

* values with a zero bit are pushed to `b`;
* values with a one bit remain in `a` through rotation;
* all values in `b` are pushed back to `a`.

The number of passes is the number of bits needed to represent the ranks,
`O(log n)`, and every pass processes all `n` values. Therefore the generated
operation count is `O(n log n)`.

### Adaptive strategy

`--adaptive` selects the internal strategy after measuring disorder:

| Disorder | Strategy | Complexity class |
| --- | --- | --- |
| `< 0.2` | Simple bubble adaptation | `O(n^2)` |
| `0.2` to `< 0.5` | Medium chunk sorting | `O(n sqrt(n))` |
| `>= 0.5` | Complex binary radix sort | `O(n log n)` |

The thresholds favor the low-overhead simple strategy when the input is already
close to sorted, use chunking for intermediate disorder, and reserve radix
passes for highly disordered inputs. The adaptive selection itself is constant
time after the disorder measurement. The disorder computation uses all pairs,
so it requires `O(n^2)` comparisons and `O(1)` additional working space; the
sorting routines use the two required stacks and `O(1)` auxiliary state.

## Project structure

```text
include/                 Public project headers
src/parsing/             Integer validation and disorder calculation
src/instructions/        Push_swap operation definitions
src/run/                 Stack state, strategy selection, and benchmark output
src/sorters/             Small, simple, medium, and complex sorters
lib/libft/               Local libft implementation
lib/lists/               Local linked-list implementation
lib/ft_printf/           Local formatted-output implementation
Push-Swap-Tester/        Optional tester and checker resources
```

## Resources

* [42 Push_swap subject](https://cdn.intra.42.fr/pdf/pdf/113661/en.subject.pdf)
  - project rules, operation definitions, complexity requirements, and
  benchmark targets.
* [Big O notation - Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
  - reference for comparing algorithm growth rates.
* [Radix sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
  - background for the binary LSD strategy.
* [Square root decomposition - CP-Algorithms](https://cp-algorithms.com/data_structures/sqrt_decomposition.html)
  - background for chunk sizes based on `sqrt(n)`.
  - man
  - man man
  - man google

### AI usage

AI assistance was used to inspect the repository and the 42 subject, organize
this README, and check that the documented commands, flags, strategies,
thresholds, complexity claims, and benchmark behavior match the source code.
The README is documentation of this repository; implementation decisions and
code changes remain the responsibility of the project author.
Any AI used was checked, double checked, triple checked by human.

## Author

* `vrouxel` - implementation, algorithm selection, testing, and documentation.
  `paukowal`- algorithms implementation and selection.
  `vrouxel` - implementation, testing, reviewing.