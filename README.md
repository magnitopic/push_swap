# Push Swap

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

https://github.com/magnitopic/push_swap/assets/21156058/a18ae060-f8a7-4b4e-a356-a4eb3c4e3793

> Video of program execution on YouTube: [https://youtu.be/CugSe5HDVrg](https://youtu.be/CugSe5HDVrg)

# Program

## Initial installation

```
git clone https://github.com/magnitopic/push_swap.git
cd push_swap
git submodule init
git submodule update
```

## Compilation and execution

```
make
./push_swap 3 2 1
```

## Count amount of moves

```
./push_swap 3 2 1 | wc -l
```

## Counting execution time

```
time ./push_swap 3 2 1
```

# Checker program

```
make bonus
./push_swap 3 2 1 | ./checker 3 2 1
```
