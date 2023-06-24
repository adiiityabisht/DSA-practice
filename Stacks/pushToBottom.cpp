#include <iostream>
#include <stack>

using namespace std;

// Function to push an element to the bottom of a stack
void pushToBottom(stack<int>& s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }

    int top = s.top();
    s.pop();
    pushToBottom(s, element);
    s.push(top);
}

int main() {
    stack<int> myStack;

    // Pushing elements to the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << "Stack before pushing 0 to the bottom: ";
    stack<int> tempStack;
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        tempStack.push(myStack.top());
        myStack.pop();
    }

    while (!tempStack.empty()) {
        myStack.push(tempStack.top());
        tempStack.pop();
    }
    cout << endl;

    // Pushing 0 to the bottom of the stack
    pushToBottom(myStack, 0);

    cout << "Stack after pushing 0 to the bottom: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}





