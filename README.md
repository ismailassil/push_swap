# Push Swap

Welcome to the **Push Swap Project**! This project is part of the 42 School curriculum and focuses on sorting algorithms and stack manipulation. The goal is to sort a stack of integers using a limited set of operations and two stacks (`stack_a` and `stack_b`). The challenge lies in finding the most efficient sequence of operations to sort the stack with the fewest moves.

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Operations](#operations)
6. [Algorithm](#algorithm)
7. [License](#license)
8. [Acknowledgments](#acknowledgments)

---

## Introduction

The **Push Swap Project** is an algorithmic challenge where you must sort a stack of integers using two stacks and a limited set of operations. The project tests your understanding of sorting algorithms, stack data structures, and optimization techniques. The goal is to write a program that generates the shortest sequence of operations to sort the stack.

---

## Features

- **Stack Manipulation**: Use two stacks (`stack_a` and `stack_b`) to sort integers.
- **Limited Operations**: Perform operations like `push`, `swap`, `rotate`, and `reverse rotate`.
- **Efficient Sorting**: Implement an algorithm to sort the stack with the fewest moves.
- **Input Validation**: Handle input validation to ensure only valid integers are processed.
- **Visualization**: Optional visualization of the sorting process (if implemented).

---

## Installation

To get started with the **Push Swap Project**, follow these steps:

1. **Clone the repository**:

   ```bash
   git clone https://github.com/ismailassil/push_swap.git
   cd push_swap
   ```

2. **Build the project**:

   ```bash
   make
   ```

3. **Run the program**:

   ```bash
   ./push_swap <list_of_integers>
   ```

   Replace `<list_of_integers>` with a space-separated list of integers to sort.

---

## Usage

The program takes a list of integers as input and outputs a sequence of operations to sort the stack. For example:

```bash
./push_swap 3 1 2 4
```

This will output a sequence of operations like `sa`, `pb`, `ra`, etc., to sort the stack.

You can also check the number of operations using the `wc` command:

```bash
./push_swap 3 1 2 4 | wc -l
```

---

## Operations

The following operations are allowed:

- **`sa`**: Swap the first two elements of `stack_a`.
- **`sb`**: Swap the first two elements of `stack_b`.
- **`ss`**: Perform `sa` and `sb` simultaneously.
- **`pa`**: Push the first element of `stack_b` to `stack_a`.
- **`pb`**: Push the first element of `stack_a` to `stack_b`.
- **`ra`**: Rotate `stack_a` (shift all elements up by one).
- **`rb`**: Rotate `stack_b` (shift all elements up by one).
- **`rr`**: Perform `ra` and `rb` simultaneously.
- **`rra`**: Reverse rotate `stack_a` (shift all elements down by one).
- **`rrb`**: Reverse rotate `stack_b` (shift all elements down by one).
- **`rrr`**: Perform `rra` and `rrb` simultaneously.

---

## Algorithm

The project requires implementing an efficient sorting algorithm. Common approaches include:

- **Simple Sort**: For small stacks (e.g., 3 or 5 elements), use a predefined sequence of moves.
- **Quicksort**: Use a pivot-based approach to partition and sort the stack.
- **Merge Sort**: Divide the stack into smaller parts, sort them, and merge.
- **Custom Algorithms**: Combine multiple techniques to optimize the number of moves.

The goal is to minimize the number of operations while ensuring the stack is sorted.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

## Acknowledgments

- **42 School**: For providing the opportunity and resources to work on this project.
- **Contributors**: Everyone who has contributed to the development of this project.

---

Thank you for checking out the **Push Swap Project**! If you have any questions or feedback, please feel free to open an issue or reach out to the maintainers.

Happy sorting! 🚀
