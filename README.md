# Printf (or at least something like printf)

Creators: Sam Henderson, Bevan Tan, Andrew Perry

## Introduction

The intention behind this was to create a function that could be used in place of printf, allowing the user to print text to stdout, with an option to unite 'substrings' with the main string where the user intends. What we instead have is a slightly worse version of printf, with a limited range of features and a far more fragile operation than the original. Any user of \_printf should expect it to occasionally deviate from the expected behaviour outlined in this manual. This is due to reasons mostly unknown by its creators, or else for reasons known to its creators but which were considered too picayune to bother with or too hard to solve in a week. We recommend that anyone thinking of using this function in their own project should reconsider this decision, as the standard printf function will perform considerably better in most if not all circumstances. The original printf function can be added to your project by including the standard input/output library in any relevant files, and then employing it using 'printf(format, substring1, substring2, ...)'.

However, if the user is determined to use this particular version of printf, then this manual will provide greater detail about adding it to a local project, and the behaviour that is intended to have (regardless of whether this behaviour is what actually occurs). 

Any pull requests that attempt to fix the workings of this function will be appreciated and then very likely ignored.

We hope you enjoy the rollercoaster of errors, bugs and occasional triumphs of \_printf.

Sincerly,

Sam, Bevan and Andrew

## Description

\_printf prints a series of characters to stdout based on the options provided to the 'format' string. More information about the 'format' argument can be found within the [format section](#format argument), but put simply, format can be considered the template for what will be printed to stdout. The user can modify the final output by including a limited range of options within the format string, which will replace the option characters with the value of certain arguments when printed to stdout. These options can be found within the [SPECIFIER HANDLING](#specifier-handling) section.


## Using \_printf locally

To use \_printf on your machine, you can use GitHub submodules to add this repo to your project. Using submodules rather than clone is preferred, as it will ensure that any future commits of your project will push to your repo rather than this one. 

When calling \_printf in your project, ensure any files using it includes main.h at the top of the file. For example:
```
#include "main.h"

int main(void)
{

...

}
```

To add this repo to your project locally: 
1. go to the main page of this repo and click "<> Code"
2. copy the link provided under HTTPS to clone using the web URL or, if you prefer to use GitHub's command line interface, copy the code provided in the GitHub CLI option 
3. open terminal or equivalent, cd into your project, then run the following command:
```
git submodule add https://github.com/force-push-main/holbertonschool-printf
```

By default, submodules will add the \_printf files into a directory named the same as the repository. By running git status, you should see something to this:
```
$ git status
On branch main
Your branch is up-to-date with 'origin/main'.

Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	new file:   .gitmodules
	new file:   holbertsonschool_printf
```
The new .githubmodules configuration file stores the mapping between the project's URL and the local subdirectory you've pulled it into. Opening the file, you should see something like this:
```
[submodule "holbertonschool_printf"]
	path = holbertonschool_print
	url = https://github.com/force-push-main/holbertonschool-printf
```

You should now be ready to use \_printf wherever you need.

For more information about using GitHub submodules, you can refer to [git official docs on submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules).

## Format argument

'Format' is the initial string that is passed as the first argument in \_printf. This will be the 'template' for the final output, and will be printed to stdout exactly as it is written excpet where a secondary 'option' is added. These options (or 'conversion specifiers') are explained in greater detail in the [SPECIFIER HANDLING section](#specifier-handling), but as an example \_printf("Jimmy has %i apples", 5) will print: Jimmy has 5 apples, to stdout when the function is run. It is a requirement that format is written within quotation marks and as the first argument, which will indicate to \_printf that this is the format string that it should print.

Format can be made up of only the options specified, however these must still be placed within quotation marks. By default, \_printf does not print a new line character at the end of the string, so users wanting a new line to proceed the string must include this character where desired.

If the format argument is left blank, it will print only the null terminating character to stdout, regardless of how many options are added afterwards.


## \_printf behaviour and options

The options available to the user are limited, however it includes a number of core data types as well as several more estoeric data types. This includes chars, ints and strings, as well as binary and hex conversions.

When adding the specifiers to the format string, it will pull the value from the following arguments passed to \_printf in sequential order, so it is important to match the order of arguments with the order that the user is expecting them to appear.

When using a specifier, it should be immediately preceeded by a '%' sign, which will inform \_printf that the character that follows will likely be a value found in the additional arguments passed to it.

In the case where a non-specifier character occurs immediately after a % sign, it will instead print the % and non-specifier character as is.



# SPECIFIER HANDLING

## s

The print\_string function is used to handle the %s format specifier. When a %s is encountered in the format string, this function is called to process and print a string argument.

### SPECIFIER BEHAVIOR

### Argument Retrieval

- Uses va_arg(arg, char\*) to extract a string pointer from the variable argument list
- Expects a null-terminated character array (string) as the argument.


### NULL STRING HANDLING

- Checks if the retrieved string is NULL
- If NULL, replaces the string with the literal "(null)"
- Ensures the function can handle uninitialized or invalid string pointers safely


### CHARACTER PRINTING

- Iterates through each character of the string until the null terminator
- Uses \_putchar() to output each character individually
- Simultaneously increments a character count


### CHARACTER COUNTING

- Maintains an accurate count of characters printed
- Returns the total number of characters output
- Allows tracking of output length for further processing



### EXAMPLE

- \_printf("Name: %s\n", "Alice");      // Prints "Name: Alice"
- \_printf("Empty: %s\n", NULL);        // Prints "Name: (null)"

### ERROR HANDLING

- No memory allocation or modification of input string
- Safe handling of NULL input
- Does not modify the original string pointer

### NOTES

- Relies on a custom _putchar() implementation for character output
- Part of a custom printf implementation

___

** c

The print_char function is designed to handle the %c format specifier in a custom printf-like implementation, processing and printing a single character argument.

### SPECIFIER BEHAVIOR

### ARGUMENT RETRIEVAL

- Uses va_arg(arg, int) to extract a character from the variable argument list
- Note: Characters are promoted to integers when passed through variable arguments
- Explicitly cast back to a character type


### CHARACTER PRINTING

- Uses \_putchar() to output the single character
- Always prints exactly one character
- Hardcoded length of 1 to track output


### CHARACTER COUNTING

- Returns a constant length of 1
- Indicates single character output
- Allows consistent tracking of output length



### FUNCTION DETAILS

- Input Type: Accepts a single character
- Output: Prints the character directly
- Return Value: Always returns 1

### EXAMPLE

- \_printf("First letter: %c\n", 'A');     // Prints "First letter: A"
- \_printf("Number as char: %c\n", 65);    // Prints "Number as char: A"

### IMPLEMENTATION NOTES

- Compatible with both character literals and integer values
- Simple, direct character output mechanism
- Consistent with variable argument handling in C

### WARNINGS

- Expects a valid character or character-convertible integer

___

## PERCENT SIGN HANDLING IN CUSTOM PRINTF
 
- Processing unexpected or literal percent signs in formatted output

### DESCRIPTION

- The percent sign handler manages scenarios involving unexpected or literal percent signs within a format string. 
- It provides robust handling of different % sign situations to ensure predictable output and error management.

### HANDLING SCENARIOS

1. Literal Percent Sign (%%)

- When two consecutive percent signs are encountered
- Prints a single % character
- Increments the output length by 1

2. Unrecognized Specifier

- If a % is followed by an unrecognized character
- Prints the original % character
- Increments the output length

3. Trailing Percent Sign

- If a % appears as the last character in the format string
- Sets the total length to -1 (error condition)

### BEHAVIOR EXAMPLES

- \_printf("100%%");           // Prints "100%"
- printf("Invalid %x");      // Prints "Invalid %"
- printf("Trailing %");      // Sets length to -1

### NOTES

- Part of a custom printf-like implementation



### RETURN VALUE

On success, _printf() will return the total number of bytes (characters) printed to stdout, not including the null terminator that concludes the string.

In the case of an error, such as if the user passes a single % with no specifier, _printf will instead return -1.
