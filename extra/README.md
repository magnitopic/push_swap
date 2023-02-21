# Python testing

In order to solve Push_Swap I wanted to break down the problem into separate steps.
First I'd need to understand what sort of algorithm I'm going to use. So I take a look at dynamic programing.
Next I'll need to program that algorithm in Python, just so I don't have to bother with handling memory.
Finally do the project in C and check that I have every thing the subject asks of me.


-	pushSwap-python
	-	dynamicProgramming.py → Implementation of a possible solution using memoization. Works fine for 2-7 numbers but wait times get too big if more numbers are introduced.
	-	modern_times.py → Current solution
-	pythonTesting → Exercise examples for dynamic programing implementation

# Dynamic programing

These exercises are from [this YouTube video](https://www.youtube.com/watch?v=oBt53YbR9Kk) by [freeCodeCamp.org](https://www.youtube.com/channel/UC8butISFwT-Wl7EV0hUK0BQ) on dynamic programing.

### Exercises

-   `fibonacci.py` - given a number it returns that position of the fibonacci sequence

-   `gridTraveler.py` - given a grid of `x,y`, you must travel form the top left corner to the bottom right corner. You can only move down or right. How many ways can you travel the grid?

-   `canSum.py` - given a number and an array of numbers, you must return True or False if it is posible sum the first number with the numbers in the array. You can repeat the same number as much as you want
-   `howSum.py` - given a number and an array of numbers, you must return an array of numbers that sum the first number. You can repeat the same number as much as you want

-   `bestSum.py` - given a number and an array of numbers, you must return an array of numbers that sum the first number. You can repeat the same number as much as you want. You must return the shortest array

-   `canConstruct.py` - given a string and an array of strings, you must return True or False if it is posible to construct the first string with the strings in the array. You can repeat the same string as much as you want

-   `countConstruct.py` - given a string and an array of strings, you must return the number of ways you can construct the first string with the strings in the array. You can repeat the same string as much as you want

-   `allConstruct.py` - given a string and an array of strings, you must return a matrix containing all of the ways the first string can be constructed by the strings in the array. You can repeat the same string as much as you want

## Conclusion on dynamic programing

Although dynamic programming is an incredibly powerful tool which can be used to solve many algorithmic challenges, it's not not a good option for the PushSwap project.

I don't doubt it can be done using dynamic programming but it is too complex and there are better options that are more suited for the task.
