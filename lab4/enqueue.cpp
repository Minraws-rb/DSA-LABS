#include<iostream>
using namespace std;
#define MAX 300
class queue {
    private:
    int a[MAX];
    int front = 0;
    int rear = -1;

    public:
    void enqueue(int n) {
        if( rear == MAX - 1) {
            cout<<"Queue overflow"<<endl;
        } else {
            rear++;
            a[rear] = n;
            cout<<n<<" is added to the queue"<< endl;
        }
    }
    int dequeue() {
        int i, v;
        if( front >rear) {
            cout<<"Queue underflow"<< endl;
            return -1;
        } else {
            v = a[front];
            front ++;
            cout<<v<<"  is dequeued"<<endl;
            return v;
        }
    }
    void display() {
        int i;
        for(i = front; i<= rear; i ++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    queue q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    return 0;
}