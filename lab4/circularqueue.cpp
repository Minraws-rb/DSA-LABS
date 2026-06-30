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
            return;
        } else {
            if(rear+1 == MAX){
                rear = 0;
            }else{
                rear++;
            }
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
            if(front+1 == MAX) {
                front = 0;
            } else {
                front ++;
             }
            count--;
            return v;
        }
    }

   void display() {
    if (count == 0) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue: ";

    int i = front;
    for (int j = 0; j < count; j++) {
        cout << a[i] << " ";
           if(i+1 == MAX){
                i = 0;
            }else{
                i++;
            }
    }
    cout << endl;
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
    q.enqueue(10);     
    q.dequeue();       
    q.dequeue();        
    q.display();
    q.enqueue(10);    
    q.enqueue(20);     
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();       
    return 0;
}