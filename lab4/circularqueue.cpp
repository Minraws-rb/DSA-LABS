#include<iostream>
using namespace std;
#define MAX 5

class CircularQueue {
private:
    int a[MAX];
    int front;
    int rear;
    int count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int n) {
        if (count == MAX) {
            cout << "Queue overflow" << endl;
        } else {
            rear = (rear + 1) % MAX;
            a[rear] = n;
            count++;
            cout << n << " is added to the queue" << endl;
        }
    }

    int dequeue() {
        if (count == 0) {
            cout << "Queue underflow" << endl;
            return -1;
        } else {
            int v = a[front];
            front = (front + 1) % MAX;
            count--;
            return v;
        }
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue: ";
            for (int i = 0; i < count; i++) {
                cout << a[(front + i) % MAX] << " ";
            }
            cout << endl;
        }
    }

    bool isFull() {
        return count == MAX;
    }

    bool isEmpty() {
        return count == 0;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(8);
    q.display();

    q.enqueue(10);      // overflow — queue is full

    q.dequeue();        // removes 2
    q.dequeue();        // removes 4
    q.display();

    q.enqueue(10);      // wraps around — fills slot 0
    q.enqueue(20);      // fills slot 1
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();        // underflow
    return 0;
}