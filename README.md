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

\_printf prints a series of characters to stdout based on the options provided to the 'format' string. More information about the 'format' argument can be found within the [format section](#format argument), but put simply, format can be considered the template for what will be printed to stdout. The user can modify the final output by including a limited range of options within the format string, which will replace the option characters with the value of certain arguments when printed to stdout. These options can be found within the [\_printf behaviour section](#_printf-behaviour-and-options).


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

'Format' is the initial string that is passed as the first argument in \_printf. This will be the 'template' for the final output, and will be printed to stdout exactly as it is written excpet where a secondary 'option' is added. These options (or 'conversion specifiers') will be explained in greater detail later, but as an example \_printf("Jimmy has %i apples", 5) will print: Jimmy has 5 apples, to stdout when the function is run. It is a requirment that format is written within quotation marks and as the first argument, which will indicate to \_printf that this is the format string that it should print.

Format can be made up of only the options specified, however these must still be placed within quotation marks. By default, \_printf does not print a new line character at the end of the string, so users wanting a new line to proceed the string must include this character where desired.

If the format argument is left blank, it will print only the null terminating character to stdout, regardless of how many options are added afterwards.


## \_printf behaviour and options

The options available to the user are limited, however it includes a number of core data types as well as several more estoeric data types. This includes chars, ints and strings, as well as binary and hex conversions.



### Return value

On success, \_printf() will return the total number of bytes (characters) printed to stdout, not including the null terminator that concludes the string.

In the case of an error, \_printf will instead return -1.
