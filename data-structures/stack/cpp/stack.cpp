#include <iostream>
#include <stack>
using namespace std;


// Stack for int numbers


//----------------------------Stack implementation with dynamic array ----------------------------//


class StackArray {
private:
    int* data;
    int topIndex;
    int capacity;

    // resize the array to fit more numbers;
    void resize() {
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        for (int i = 0; i <= topIndex; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    //constructor
    StackArray(int initialCapacity = 4) {
        if (initialCapacity <= 0) {
            cout << "Capacity must be greater than zero.\n";
            exit(1);
        }

        data = new int[initialCapacity];
        topIndex = -1;
        capacity = initialCapacity;
    }

    // destructor
    ~StackArray() {
        delete[] data;
    }

    // check if its empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // check if its full
    bool isFull() const {
        return topIndex == capacity - 1;
    }

    // return the size
    int size() const {
        return topIndex + 1;
    }

    //return the capacity
    int getCapacity() const {
        return capacity;
    }

    // add number to top;
    void push(int value) {
        if (isFull()) {
            resize();
        }

        topIndex++;
        data[topIndex] = value;
    }

    // remove top item and return it;
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow: cannot pop from an empty stack.\n";
            exit(1);
        }

        int value = data[topIndex];
        topIndex--;
        return value;
    }

    //return top value;
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty: cannot peek.\n";
            exit(1);
        }

        return data[topIndex];
    }

    // print stack
    void print() const {
        if (isEmpty()) {
            cout << "Stack: [empty]\n";
            return;
        }

        cout << "Stack (bottom -> top):\n[ ";
        for (int i = 0; i <= topIndex; i++) {
            cout << data[i] << " ";
        }
        cout << "]\n";
    }
};



//----------------------------Stack implementation with linked list ----------------------------//


class StackList {
private:
    struct Node {
        int value;
        Node* next;

        Node(int value, Node* next = nullptr) {
            this->value = value;
            this->next = next;
        }
    };

    Node* topNode;
    int stackSize;

public:
    // constructor;
    StackList() {
        topNode = nullptr;
        stackSize = 0;
    }

    // destructor
    ~StackList() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // check if its empty
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // return the size
    int size() const {
        return stackSize;
    }

    //add item to top;
    void push(int value) {
        Node* newNode = new Node(value, topNode);
        topNode = newNode;
        stackSize++;
    }

    //remove and return the top value;
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow: cannot pop from an empty stack.\n";
            exit(1);
        }

        Node* temp = topNode;
        int poppedValue = temp->value;

        topNode = topNode->next;
        delete temp;
        stackSize--;

        return poppedValue;
    }

    // return the top value;
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty: cannot peek.\n";
            exit(1);
        }

        return topNode->value;
    }

    // print stack
    void print() const {
        if (isEmpty()) {
            cout << "Stack: [empty]\n";
            return;
        }

        Node* current = topNode;
        cout << "Stack (top -> bottom):\n[ ";
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "]\n";
    }
};


// std::stack is a container adapter provided by the C++ Standard Library.
// It offers the main stack operations such as push, pop, top, size, and empty.


//----------------------------Example of use ----------------------------//

// method just for printing std data
void printStdStack(std::stack<int> stack) {
    if (stack.empty()) {
        std::cout << "Stack: [empty]\n";
        return;
    }

    std::cout << "std::stack (top -> bottom):\n[ ";
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << "]\n";
}

int main() {
    StackArray arrayStack(4);
    StackList listStack;

    int values[] = {10, 20, 30, 40, 50};
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Pushing the same values into both stacks:\n";
    for (int i = 0; i < n; i++) {
        arrayStack.push(values[i]);
        listStack.push(values[i]);
    }

    cout << "\n=== Initial comparison ===\n";

    cout << "Array-based stack:\n";
    arrayStack.print();
    cout << "Top: " << arrayStack.peek()
         << " | Size: " << arrayStack.size()
         << " | Capacity: " << arrayStack.getCapacity() << "\n";

    cout << "\nLinked-list-based stack:\n";
    listStack.print();
    cout << "Top: " << listStack.peek()
         << " | Size: " << listStack.size() << "\n";

    cout << "\nPopping one element from both stacks...\n";
    int poppedArray = arrayStack.pop();
    int poppedList = listStack.pop();

    cout << "Popped from array-based stack: " << poppedArray << "\n";
    cout << "Popped from linked-list-based stack: " << poppedList << "\n";

    cout << "\n=== After one pop ===\n";

    cout << "Array-based stack:\n";
    arrayStack.print();
    cout << "Top: " << arrayStack.peek()
         << " | Size: " << arrayStack.size()
         << " | Capacity: " << arrayStack.getCapacity() << "\n";

    cout << "\nLinked-list-based stack:\n";
    listStack.print();
    cout << "Top: " << listStack.peek()
         << " | Size: " << listStack.size() << "\n";

    cout << "\n//------------------------------ C++ Standard Library stack -------------------------------//\n";

    std::stack<int> stdStack;

    cout << "\nPushing the same values into std::stack:\n";
    for (int i = 0; i < n; i++) {
        stdStack.push(values[i]);
    }

    printStdStack(stdStack);
    cout << "Top: " << stdStack.top()
         << " | Size: " << stdStack.size()
         << " | Empty: " << (stdStack.empty() ? "true" : "false") << "\n";

    cout << "\nPopping one element from std::stack...\n";
    int poppedStd = stdStack.top();
    stdStack.pop();

    cout << "Popped from std::stack: " << poppedStd << "\n";

    printStdStack(stdStack);
    cout << "Top: " << stdStack.top()
         << " | Size: " << stdStack.size()
         << " | Empty: " << (stdStack.empty() ? "true" : "false") << "\n";

    cout << "\nOther std::stack examples:\n";

    std::stack<int> exampleStack;
    cout << "exampleStack.empty(): " << (exampleStack.empty() ? "true" : "false") << "\n";

    exampleStack.push(100);
    exampleStack.push(200);
    exampleStack.push(300);

    cout << "After pushing 100, 200, 300:\n";
    cout << "exampleStack.top(): " << exampleStack.top() << "\n";
    cout << "exampleStack.size(): " << exampleStack.size() << "\n";
    cout << "exampleStack.empty(): " << (exampleStack.empty() ? "true" : "false") << "\n";

    exampleStack.pop();
    cout << "After one pop, exampleStack.top(): " << exampleStack.top() << "\n";
    cout << "After one pop, exampleStack.size(): " << exampleStack.size() << "\n";

    return 0;
}