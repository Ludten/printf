# A custom printf called `_printf`

The learning objective of this projects are: Putting all knowledge learnt in C so far into creating the function.

## Highlights and Design Goals

The *_printf* implementation meets the following items:

 - NO dependencies, no libs, just one module file
 - Support of all important flags, width and precision sub-specifiers (see below)
 - Support of decimal/integer number representation
 - no static vars/buffers
 - Custom specifiers implemetations
 	- r: to reverse string
  	- R: ROT13 encoding
  	- S: replacing (0 < ASCII value < 32 or >= 127) with `\x` followed by their hexadecimal values
 - Simply the best *_printf* around the alx cohort5

## Usage

Add/link *printf.c* to your project and include *main.h*. That's it.
Implement your low level output function needed for `printf()`:
```C
void _putchar(char character)
{
  // send char to console etc.
}
```

Usage is 1:1 like the according stdio.h library version:
```C
int printf(const char* format, ...);
```
## Format Specifiers

A format specifier follows this prototype: `%[flags][width][.precision][length]type`
The following format specifiers are supported:


### Supported Types

| Type   | Output |
|--------|--------|
| d or i | Signed decimal integer |
| u      | Unsigned decimal integer	|
| b      | Unsigned binary |
| o      | Unsigned octal |
| x      | Unsigned hexadecimal integer (lowercase) |
| X      | Unsigned hexadecimal integer (uppercase) |
| c      | Single character |
| s      | String of characters |
| p      | Pointer address |
| %      | A % followed by another % character will write a single % |

### Custom Specifiers
| Type   | Output |
|--------|--------|
| r | prints the reversed string |
| R      | prints the rot13'ed string     |
| S      | prints the string |

### Supported Flags

| Flags | Description |
|-------|-------------|
| -     | Left-justify within the given field width; Right justification is the default. |
| +     | Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers.<br>By default, only negative numbers are preceded with a - sign. |
| (space) | If no sign is going to be written, a blank space is inserted before the value. |
| #     | Used with o, b, x or X specifiers the value is preceded with 0, 0b, 0x or 0X respectively for values different than zero.<br>Used with f, F it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written. |
| 0     | Left-pads the number with zeros (0) instead of spaces when padding is specified (see width sub-specifier). |


### Supported Width

| Width    | Description |
|----------|-------------|
| (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| *        | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |


### Supported Precision

| Precision	| Description |
|-----------|-------------|
| .number   | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.<br>For f and F specifiers: this is the number of digits to be printed after the decimal point. **By default, this is 6, maximum is 9**.<br>For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.<br>If the period is specified without an explicit value for precision, 0 is assumed. |
| .*        | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |


### Supported Length

The length sub-specifier modifies the length of the data type.

| Length | d i  | u o x X |
|--------|------|---------|
| (none) | int  | unsigned int |
| h      | short int | unsigned short int |
| l      | long int | unsigned long int |


### Return Value

Upon successful return, all functions return the number of characters written, _excluding_ the terminating null character used to end the string.

## Contributing

0. Give this project a :star:
1. Create an issue and describe your idea
2. [Fork it](https://github.com/Ludten/printf/fork)
3. Create your feature branch (`git checkout -b my-new-feature`)
4. Commit your changes (`git commit -am 'Add some feature'`)
5. Publish the branch (`git push origin my-new-feature`)
6. Create a new pull request
7. Profit! :heavy_check_mark:

