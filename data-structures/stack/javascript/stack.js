// In JavaScript, the most common way to implement a stack is by using an Array.
// The end of the array represents the top of the stack.

function printStack(stack) {
    if (stack.length === 0) {
        console.log("Stack: [empty]");
        return;
    }

    console.log("Stack (bottom -> top):");
    console.log(stack);
}

function main() {
    const stack = [];

    console.log("// -------------------- Creating an empty stack -------------------- //");
    console.log("Initial stack:", stack);
    console.log("Is the stack empty?", stack.length === 0);

    console.log("\n// -------------------- push: push() -------------------- //");
    console.log("push(value) adds a new element to the top of the stack.\n");

    stack.push(10);
    console.log("After stack.push(10):");
    printStack(stack);

    stack.push(20);
    console.log("After stack.push(20):");
    printStack(stack);

    stack.push(30);
    console.log("After stack.push(30):");
    printStack(stack);

    console.log("\n// -------------------- peek: stack[stack.length - 1] -------------------- //");
    console.log("stack[stack.length - 1] returns the top element without removing it.\n");

    const topElement = stack[stack.length - 1];
    console.log("Top element:", topElement);
    console.log("Stack after peek:");
    printStack(stack);

    console.log("\n// -------------------- size: stack.length -------------------- //");
    console.log("stack.length returns the number of elements in the stack.\n");

    console.log("Current size:", stack.length);

    console.log("\n// -------------------- is empty -------------------- //");
    console.log("A common way to check if the stack is empty is using stack.length === 0.\n");

    console.log("stack.length === 0:", stack.length === 0);

    console.log("\n// -------------------- pop: pop() -------------------- //");
    console.log("pop() removes and returns the top element.\n");

    let removed = stack.pop();
    console.log("Removed element:", removed);
    console.log("Stack after pop():");
    printStack(stack);

    removed = stack.pop();
    console.log("Removed element:", removed);
    console.log("Stack after another pop():");
    printStack(stack);

    console.log("\n// -------------------- Final state -------------------- //");
    console.log("Top element now:", stack[stack.length - 1]);
    console.log("Current size:", stack.length);
    console.log("Is the stack empty?", stack.length === 0);
}

main();