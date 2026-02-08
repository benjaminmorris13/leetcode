#include <stack>
#include <iostream>

class MyQueue {
private:
    int size;
    std::stack<int> einstein;
    std::stack<int> real;
public:
    MyQueue() : size{0}, einstein{}, real{} {}
    
    void push(int x) {
        if (size == 0) {
            size += 1;
            real.push(x);
        }
        else { //it's not empty
            real.push(x);
            size += 1;
        }
    }

    int pop() {
        if (size == 0) {
            return -1;
        }
        else {
            size -= 1;
            int result;
            for (int i = 0; i < size; i++) {
                einstein.push(real.top());
                real.pop();
            }
            result = real.top();
            real.pop();
            for (int i = 0; i < size; i++) {
                real.push(einstein.top());
                einstein.pop();
            }
            return result;
        }
    }
    
    int peek() {
        if (size == 0) {
            return -1;
        }
        else { //it's not empty
            int result;
            for (int i = 0; i < (size - 1); i++) {
                einstein.push(real.top());
                real.pop();
            }
            result = real.top();
            for (int i = 0; i < (size - 1); i++) {
                real.push(einstein.top());
                einstein.pop();
            }
            return result;
        }
    }
    
    bool empty() {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
