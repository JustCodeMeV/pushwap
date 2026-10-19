*This project has been created as part of the 42 curriculum by vrouxel.*

# ft_printf

## Description

`ft_printf` is a 42 school project that consists of recreating the essential behavior of the standard C `printf` function.

The project focuses on variadic functions and requires the creation of a static library named `libftprintf.a`. The implementation supports the mandatory conversions `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%`, without reproducing the internal buffering system of the original libc implementation.

The project is designed to strengthen several core C programming skills:

- Handling a variable number of arguments with `<stdarg.h>`.
- Parsing a format string character by character.
- Converting signed, unsigned, decimal, and hexadecimal values to text.
- Writing reusable and modular functions.
- Building and linking a static library with `make` and `ar`.
- Managing return values and low-level output with `write`.

## Supported conversions

| Conversion | Behavior |
| --- | --- |
| `%c` | Prints one character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer in hexadecimal notation. |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned integer in lowercase hexadecimal. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

Clone the repository and enter its directory.

Build the mandatory library with:

```sh
make
```

This creates `libftprintf.a` at the root of the repository. The project must be compiled with `cc`, using `-Wall -Wextra -Werror`.

The root Makefile also builds the bundled `lib/libft.a` before creating
`libftprintf.a`. The printf library itself does not require `lib/libft.a` when
linked into a program.

### Available Makefile rules

```sh
make        # Build the library
make all    # Build the library
make clean  # Remove object files
make fclean # Remove object files and the library
make re     # Rebuild everything
```


### Using the library

Include the project header in a C source file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Value: %d\\n", 42);
    ft_printf("Address: %p\\n", (void *)main);
    return (0);
}
```

Compile the program by adding the library and its include directory:

```sh
cc -Wall -Wextra -Werror main.c -I. ./libftprintf.a -o demo
./demo
```

## Implementation and design

### Format-string parser

The main function scans the format string from left to right. Ordinary characters are written directly. When a `%` character is encountered, the next character is interpreted as a conversion specifier and dispatched to the corresponding conversion function.

Conceptually, the control flow is:

```text
for each character in format:
    if character is not '%':
        write character
    else:
        read conversion specifier
        retrieve the matching argument with va_arg
        format and write the argument
        update the total number of written characters
```

This single-pass approach is appropriate because the format string is already ordered and each conversion can be processed independently. It avoids unnecessary storage and keeps the implementation close to the behavior required by the project. A trailing `%` is treated as a literal character, while an unsupported conversion produces no output for the conversion itself.

### Variadic arguments

`ft_printf` uses a `va_list` to access arguments whose number and types are determined by the format string:

1. `va_start` initializes the argument traversal.
2. `va_arg` retrieves each argument with the type required by its conversion.
3. `va_end` releases the variadic argument state.

The implementation must retrieve arguments using the correct type. For example, `%d` and `%i` use `int`, `%u`, `%x`, and `%X` use `unsigned int`, `%s` uses `char *`, and `%p` uses `void *`.

### Number conversion

Integer output is generated recursively by repeatedly dividing a value by the target base:

- Decimal conversions use base 10.
- Hexadecimal conversions use base 16.
- Lowercase hexadecimal uses the digit table `0123456789abcdef`.
- Uppercase hexadecimal uses the digit table `0123456789ABCDEF`.

For a positive number, the remainder of division by the base selects the next digit. The quotient is then processed until no digits remain. Output is emitted in reverse mathematical order, either by recursion or by storing digits temporarily before writing them.

Signed values write the sign first and then recursively convert the magnitude. The `%d` and `%i` arguments are retrieved as `int` and passed to the decimal helper as `long`.

Pointers are converted to an unsigned integer representation and printed with the `0x` prefix. A null pointer should follow the behavior expected by the project tests and the reference implementation.

### Data structures

The implementation does not require a complex data structure. It primarily uses:

- The format string as the input sequence.
- A `va_list` for the current argument sequence.
- Digit-table strings passed to the shared base-conversion helper.
- Integer counters for the number of characters written.

This design is justified because the project processes one format specifier at a time. A token array, linked list, or dynamic formatting object would add memory and complexity without providing an advantage for the mandatory requirements.

### Return value

`ft_printf` returns the total number of characters successfully written, matching the central behavior of the standard `printf` function. Each helper returns its own output count so that the main function can accumulate the result consistently.

## Testing

The implementation should be compared with the system `printf` using identical inputs. Useful test categories include:

- Literal strings and empty strings.
- Characters, including whitespace characters.
- Normal and empty strings.
- Null string and pointer arguments, according to the expected project behavior.
- Positive, negative, zero, and maximum/minimum integer values.
- Unsigned values and hexadecimal values.
- Lowercase and uppercase hexadecimal output.
- Several conversions in one format string.
- Return-value comparisons.
- Invalid or unsupported format strings, where relevant to the implementation.

Example comparison:

```c
int expected;
int actual;

expected = printf("printf: %d %x %s\\n", -42, 255, "hello");
actual = ft_printf("ft_printf: %d %x %s\\n", -42, 255, "hello");
```

Testing tools such as `valgrind` may be used to check for invalid memory access and leaks when running a compiled client program:

```sh
valgrind --leak-check=full ./demo
```

## Resources

- `man 3 printf` — reference behavior and return-value conventions for the standard function.
- `man 3 stdarg` — documentation for `va_list`, `va_start`, `va_arg`, `va_copy`, and `va_end`.
- `man 2 write` — low-level output function used by the project.
- The ISO C documentation for integer types, conversions, and variadic functions.
- The official 42 `ft_printf` subject — project requirements, allowed functions, mandatory conversions, and bonus scope.

## Resources and AI usage

### AI usage
Any AI used during the project was double, triple, quadruple checked, and adjusted by human.
No core logic was written with AI, only human.
AI assistance was used as a documentation and review aid for this README. It helped organize the project description, explain the variadic-function workflow, describe the parsing and number-conversion strategies, and suggest a clear structure for compilation and testing instructions.
This README file was generated using Perplexity LLM then adjusted manually.

### References
- man
- man again
- C language references such as the C99 standard documentation and online C library references.
- and man again
- 42 intra documentation for project rules, the Norm, and AI guidelines.
- Lot of man google
- Lot of rubber duck talking
- Lot of fellow students <3
- Lot of coffee

*La route est longue, mais la voie est libre*