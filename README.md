# Printf (or at least something like printf)

Creators: Sam Henderson, Bevan Tan, Andrew Perry

# SPECIFIER HANDLING

## s

The print_string function is used to handle the %s format specifier. When a %s is encountered in the format string, this function is called to process and print a string argument.

### SPECIFIER BEHAVIOR

### Argument Retrieval

- Uses va_arg(arg, char*) to extract a string pointer from the variable argument list
- Expects a null-terminated character array (string) as the argument.


### NULL STRING HANDLING

- Checks if the retrieved string is NULL
- If NULL, replaces the string with the literal "(null)"
- Ensures the function can handle uninitialized or invalid string pointers safely


### CHARACTER PRINTING

- Iterates through each character of the string until the null terminator
- Uses _putchar() to output each character individually
- Simultaneously increments a character count


### CHARACTER COUNTING

- Maintains an accurate count of characters printed
- Returns the total number of characters output
- Allows tracking of output length for further processing



### EXAMPLE

- _printf("Name: %s\n", "Alice");      // Prints "Name: Alice"
- _printf("Empty: %s\n", NULL);        // Prints "Name: (null)"

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

- Uses _putchar() to output the single character
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

- _printf("First letter: %c\n", 'A');     // Prints "First letter: A"
- _printf("Number as char: %c\n", 65);    // Prints "Number as char: A"

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

###HANDLING SCENARIOS

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

- _printf("100%%");           // Prints "100%"
- printf("Invalid %x");      // Prints "Invalid %"
- printf("Trailing %");      // Sets length to -1

### NOTES

- Part of a custom printf-like implementation

___
