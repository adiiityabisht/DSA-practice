#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>& stack, int num) {
    // Base case
    if (stack.empty()) {
        stack.push(num);
        return;
    }
    int temp = stack.top();
    stack.pop();

    insertAtBottom(stack, num);
    stack.push(temp);
}

void reverseStack(stack<int>& stack) {
    if (stack.empty()) {
        return;
    }
    int num = stack.top();
    stack.pop();

    reverseStack(stack);
    insertAtBottom(stack, num);
}

int main() {
    stack<int> myStack;

    // Pushing elements to the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << "Stack before reversal: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    // Pushing elements back onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    // Reversing the stack
    reverseStack(myStack);

    cout << "Stack after reversal: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
