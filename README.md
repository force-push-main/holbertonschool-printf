# Printf (or at least something like printf)

Creators: Sam Henderson, Bevan Tan, Andrew Perry


## \_printf notes


## print\_char notes

### c = va arg(arg, int)
Initialises c to equal the value of arg, then moves to the next value in the arg array (not actually an array but easier to think of it like that).

Importantly, by moving to the next value in the arg array here, all instances of arg in all functions are now also equal to that value.

e.g. if arg = [1, 2, 3], running the va arg command here will return 1 and move arg to the next value, 2. If you run the va arg command again, either here or in the \_printf function (or wherever you want), it will return 2, and so on.

