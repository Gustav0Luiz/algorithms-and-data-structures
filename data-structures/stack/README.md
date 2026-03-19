# Stack

A stack is a linear data structure that follows the **LIFO** principle: **Last In, First Out**.

This means that the last element added to the stack is the first one to be removed.

## Main operations

- **push**: add an element to the top of the stack
- **pop**: remove the top element
- **peek / top**: view the top element without removing it
- **isEmpty**: check whether the stack is empty

## Time complexity

The following complexities assume a standard stack implementation, typically based on an array or linked list.

| Operation | Complexity |
|----------|------------|
| Push     | O(1)       |
| Pop      | O(1)       |
| Peek     | O(1)       |
| Search   | O(n)       |

> Note: when implemented with a dynamic array, `push` may be `O(n)` in the worst case during resizing, but it is typically `O(1)` amortized.
## Implementations

This folder contains stack implementations in:

- C
- C++
- Python
- JavaScript

## Notes

Stacks can be implemented using:

- arrays
- linked lists

In this repository, the goal is to understand how stacks work internally by implementing them manually before comparing them with built-in language features and libraries.