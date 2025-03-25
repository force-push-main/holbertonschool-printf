# Printf (or at least something like printf)

Creators: Sam Henderson, Bevan Tan, Andrew Perry


## \_printf notes

### Struct array

```
Spec_N_Func spec_n_func[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'d', print_neg_int},
	{'i', print_int}
        };
```
This creates an array of structs, in which we store the specifier value (e.g. 'c') and then the related function that needs to be run to print whatever value is being passed (e.g. print\_char).

Later, we can loop through this array of structs, accessing the specifier value for each struct using dot notation (aka, spec\_n\_func.spec) to check whether the character that follows '%' matches any of the specifier values in any of the structs.

If it does, then we can access the function related to that specifier (e.g. print\_char) and run it, passing the value of arg, where it will be printed (see print\_char notes for what happens next).


### Loop-de-loop

```
 length = 0;

        for (i = 0; format[i]; i++)
        {
                if (format[i] == '%')
                {
                        for (j = 0; j < 5 && format[i] != spec_n_func[j].spec; j++)
                        {
                                if (format[i + 1] == spec_n_func[j].spec)
                                {
                                        length += spec_n_func[j].print_func(args);
                                        i = i + 2;
                                }
                        }
                }
                _putchar(format[i]);
                length++;
        }
```

The first loop goes through format (which is a string), first checking whether the character at index i is equal to '%'. If it isn't, then it skips the second loop and jumps straight to the second last line (\_putchar(format[i])), which will print the character at format[i], and add one to the length counter.

However, if it does find a '%', then it enters the second loop.

```
for (j = 0; j < 5 && format[i - 1] != spec_n_func[j - 1].spec; j++)
	{
		if (format[i + 1] == spec_n_func[j].spec)
		{
			length += spec_n_func[j].print_func(args);
			i = i + 2;
		}
	}

```

Here we set j = 0, run the loop until __either__ j < 5 (which is the length of the struct array) or until it's found a match between the specifier in format and the specifiers we've saved in the struct array (spec\_n\_func.spec), __but__ only after it's run the relevant print function (which is why there's a bunch of i - 1 and j - 1 going on).

Within the loop, we're checking whether the character after the '%' (aka, format[i + 1]) is equal to one of the specifiers we stored in the struct array:

```
if (format[i + 1] == spec_n_func[j].spec)
```

If it is, then we do two things simultaneously:
1. Run the relevant print function (e.g. print\_char)
2. Add the return value of the print function (which is the number of characters that print function has printed) to our running count of characters printed (length)

```
length += spec_n_func[j].print_func(args);

```

Immediately after that, we add 2 to i, so that when the first loop starts printing characters again, it skips the % and the specifier characters, and starts printing the characters from that point onwards.

But, if it doesn't find a match, then we don't add 2 to i, so i is still pointing to the value of '%'. This means when we exit the loop, if we didn't find a match then we will print the % and the unknown specifier (e.g. if we're given %r, then it will still print %r).






## print\_char notes

```
c = va arg(arg, int)
```

Initialises c to equal the value of arg, then moves to the next value in the arg array (not actually an array but easier to think of it like that).

Importantly, by moving to the next value in the arg array here, all instances of arg in all functions are now also equal to that value.

e.g. if arg = [1, 2, 3], running the va arg command here will return 1 and move arg to the next value, 2. If you run the va arg command again, either here or in the \_printf function (or wherever you want), it will return 2, and so on.

