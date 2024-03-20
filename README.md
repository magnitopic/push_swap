# Push Swap

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

https://github.com/magnitopic/push_swap/assets/21156058/a18ae060-f8a7-4b4e-a356-a4eb3c4e3793

> Video of program execution on YouTube: [https://youtu.be/CugSe5HDVrg](https://youtu.be/CugSe5HDVrg)

# Program

## Initial installation

```bash
git clone https://github.com/magnitopic/push_swap.git
cd push_swap
git submodule init
git submodule update
```

## Compilation and execution

```bash
make
./push_swap 3 2 1
```

## Count amount of moves

```bash
./push_swap 3 2 1 | wc -l
```

## Counting execution time

```bash
time ./push_swap 3 2 1
```

# Checker program

The **bonus** part of the project is to develop a checker program for the mandatory part. This program will receive the numbers and the instructions from the standard input and will check if the numbers are sorted.

```bash
make bonus
./push_swap 3 2 1 | ./checker 3 2 1
```

# Online visualizer

You can run Push_swap in [this online visualizer.](https://push-swap-visualizer.vercel.app)

Execute the program with the numbers the page generates and place the output in a file.
You can later upload it and see the execution of the program.

```bash
./push_swap 3 2 5 4 1 > result
```
