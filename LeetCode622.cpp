class MyCircularQueue {
private:
    int* array;
    int front;
    int rear;
    int size;
public:
    MyCircularQueue(int k) : array{new int[k]{}}, front{-1}, rear{-1}, size{k} {}
    
    bool enQueue(int value) {
        if (this->isEmpty()) {
            array[0] = value;
            front = 0;
            rear = 0;
            return true;
        }
        else if (this->isFull()) {
            return false;
        }
        else {
            rear = (rear + 1) % size;
            array[rear] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if (this->isEmpty()) {
            return false;
        }
        else {
            if (front == rear) {
                front = -1;
                rear = -1;
                return true;
            }
            else {
                front = (front + 1) % size;
                return true;
            }
        }
    }
    
    int Front() {
        if (this->isEmpty()) {
            return -1;
        }
        else {
            return array[front];
        }
    }
    
    int Rear() {
        if (this->isEmpty()) {
            return -1;
        }
        else {
            return array[rear];
        }
    }
    
    bool isEmpty() {
        if ((front == -1) && (rear == -1)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool isFull() {
        if ((rear + 1) % size == front) {
            return true;
        }
        else {
            return false;
        }
    }
};
