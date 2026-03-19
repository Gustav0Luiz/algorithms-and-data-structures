#include <stdio.h>
#include <stdlib.h>

// Stack for int numbers



//----------------------------Stack implementation with dynamic array ----------------------------//



struct StackArray {
    int *data; // pointer to the vector of int
    int top;   // index of the top (if -1 its empty)
    int capacity; 
};


// function that creates the struct and sets up the data;
void stackArrayInit(struct StackArray *stack, int initialCapacity) {
    if (initialCapacity <= 0) {
        printf("Capacity must be greater than zero.\n");
        exit(1);
    }

    // alocate memory to the vector data;
    stack->data = (int *)malloc(initialCapacity * sizeof(int));
    if (stack->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // if top = -1 the stack is empty;
    stack->top = -1;
    // stack capacity is defined here
    stack->capacity = initialCapacity;
}

// check if the stack is empty
int stackArrayIsEmpty(const struct StackArray *stack) {
    return stack->top == -1;
}

// check if the stack is full
int stackArrayIsFull(const struct StackArray *stack) {
    return stack->top == stack->capacity - 1;
}

// return the number os elements of the stack
int stackArraySize(const struct StackArray *stack) {
    return stack->top + 1;
}

// increases the capacity of the stack by twice;
void stackArrayResize(struct StackArray *stack) {
    int newCapacity = stack->capacity * 2;
    int *newData = (int *)realloc(stack->data, newCapacity * sizeof(int));

    if (newData == NULL) {
        printf("Memory reallocation failed.\n");
        free(stack->data);
        exit(1);
    }

    stack->data = newData;
    stack->capacity = newCapacity;
}


// add new number to the top
void stackArrayPush(struct StackArray *stack, int value) {
    if (stackArrayIsFull(stack)) {
        stackArrayResize(stack);
    }

    stack->top++;
    stack->data[stack->top] = value;
}

// remove the top number and return it;
int stackArrayPop(struct StackArray *stack) {
    if (stackArrayIsEmpty(stack)) {
        printf("Stack underflow: cannot pop from an empty stack.\n");
        exit(1);
    }

    int value = stack->data[stack->top];
    stack->top--;
    return value;
}

// just return the value of top element
int stackArrayPeek(const struct StackArray *stack) {
    if (stackArrayIsEmpty(stack)) {
        printf("Stack is empty: cannot peek.\n");
        exit(1);
    }

    return stack->data[stack->top];
}


// print the stack
void stackArrayPrint(const struct StackArray *stack) {
    if (stackArrayIsEmpty(stack)) {
        printf("Stack: [empty]\n");
        return;
    }

    printf("Stack (bottom -> top): ");
    printf("\n[");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("]");
    printf("\n");
}

// free the memory and reset the counters;
void stackArrayFree(struct StackArray *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->top = -1;
    stack->capacity = 0;
}





//----------------------------Stack implementation with linked list ----------------------------//


// A linked-list stack stores each element in a node, where each node points to
// the next one, and the stack top always points to the most recently added node.


struct Node {
    int value;
    struct Node *next;
};

struct StackList {
    struct Node *top;
    int size;
};

// start with size 0;
void stackListInit(struct StackList *stack) {
    stack->top = NULL;
    stack->size = 0;
}

// check if stack is empty;
int stackListIsEmpty(const struct StackList *stack) {
    return stack->top == NULL;
}

// return the size of the stack;
int stackListSize(const struct StackList *stack) {
    return stack->size;
}

// add one more element to the stack;
void stackListPush(struct StackList *stack, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// return the value of the top element;
int stackListPeek(const struct StackList *stack) {
    if (stackListIsEmpty(stack)) {
        printf("Stack is empty: cannot peek.\n");
        exit(1);
    }

    return stack->top->value;
}

// remove the top element and return it;
int stackListPop(struct StackList *stack) {
    if (stackListIsEmpty(stack)) {
        printf("Stack underflow: cannot pop from an empty stack.\n");
        exit(1);
    }

    struct Node *temp = stack->top;
    int poppedValue = temp->value;

    stack->top = stack->top->next;
    free(temp);
    stack->size--;

    return poppedValue;
}

// print the stack
void stackListPrint(const struct StackList *stack) {
    if (stackListIsEmpty(stack)) {
        printf("Stack: [empty]\n");
        return;
    }

    struct Node *current = stack->top;
    printf("Stack (top -> bottom): ");
    printf("\n[");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("]");
    printf("\n");
}

// resets the stack and free memory
void stackListFree(struct StackList *stack) {
    struct Node *current = stack->top;

    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    stack->top = NULL;
    stack->size = 0;
}





//  C does not provide a built-in stack data structure in its standard library,
//  so stacks are usually implemented manually using arrays or linked lists.




// example of use;
int main() {
  
    struct StackArray arrayStack;
    struct StackList listStack;

    stackArrayInit(&arrayStack, 4);
    stackListInit(&listStack);

    int values[] = {10, 20, 30, 40, 50};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Pushing the same values into both stacks:\n");
    for (int i = 0; i < n; i++) {
        stackArrayPush(&arrayStack, values[i]);
        stackListPush(&listStack, values[i]);
    }

    printf("\n=== Initial comparison ===\n");
    printf("Array-based stack:\n");
    stackArrayPrint(&arrayStack);
    printf("Top: %d | Size: %d | Capacity: %d\n",
           stackArrayPeek(&arrayStack),
           stackArraySize(&arrayStack),
           arrayStack.capacity);

    printf("\nLinked-list-based stack:\n");
    stackListPrint(&listStack);
    printf("Top: %d | Size: %d\n",
           stackListPeek(&listStack),
           stackListSize(&listStack));

    printf("\nPopping one element from both stacks...\n");
    int poppedArray = stackArrayPop(&arrayStack);
    int poppedList = stackListPop(&listStack);

    printf("Popped from array-based stack: %d\n", poppedArray);
    printf("Popped from linked-list-based stack: %d\n", poppedList);

    printf("\n=== After one pop ===\n");
    printf("Array-based stack:\n");
    stackArrayPrint(&arrayStack);
    printf("Top: %d | Size: %d | Capacity: %d\n",
           stackArrayPeek(&arrayStack),
           stackArraySize(&arrayStack),
           arrayStack.capacity);

    printf("\nLinked-list-based stack:\n");
    stackListPrint(&listStack);
    printf("Top: %d | Size: %d\n",
           stackListPeek(&listStack),
           stackListSize(&listStack));

    stackArrayFree(&arrayStack);
    stackListFree(&listStack);

    return 0;
}