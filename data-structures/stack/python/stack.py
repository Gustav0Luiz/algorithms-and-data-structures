# In Python, the most common way to implement a stack is by using a list.
# The end of the list represents the top of the stack.

def print_stack(stack):
    if not stack:
        print("Stack: [empty]")
        return

    print("Stack (bottom -> top):")
    print(stack)


def main():
    stack = []

    print("// -------------------- Creating an empty stack -------------------- //")
    print(f"Initial stack: {stack}")
    print(f"Is the stack empty? {len(stack) == 0}")

    print("\n// -------------------- push: append() -------------------- //")
    print("append(value) adds a new element to the top of the stack.\n")

    stack.append(10)
    print("After stack.append(10):")
    print_stack(stack)

    stack.append(20)
    print("After stack.append(20):")
    print_stack(stack)

    stack.append(30)
    print("After stack.append(30):")
    print_stack(stack)

    print("\n// -------------------- peek: stack[-1] -------------------- //")
    print("stack[-1] returns the top element without removing it.\n")

    top_element = stack[-1]
    print(f"Top element: {top_element}")
    print("Stack after peek:")
    print_stack(stack)

    print("\n// -------------------- size: len(stack) -------------------- //")
    print("len(stack) returns the number of elements in the stack.\n")

    print(f"Current size: {len(stack)}")

    print("\n// -------------------- is empty -------------------- //")
    print("A common way to check if the stack is empty is using 'not stack' or len(stack) == 0.\n")

    print(f"Using 'not stack': {not stack}")
    print(f"Using 'len(stack) == 0': {len(stack) == 0}")

    print("\n// -------------------- pop: pop() -------------------- //")
    print("pop() removes and returns the top element.\n")

    removed = stack.pop()
    print(f"Removed element: {removed}")
    print("Stack after pop():")
    print_stack(stack)

    removed = stack.pop()
    print(f"Removed element: {removed}")
    print("Stack after another pop():")
    print_stack(stack)

    print("\n// -------------------- Final state -------------------- //")
    print(f"Top element now: {stack[-1]}")
    print(f"Current size: {len(stack)}")
    print(f"Is the stack empty? {not stack}")


if __name__ == "__main__":
    main()