#include<iostream>
using namespace std;
#define MAX 30
class queue {
    private:
    int a[MAX];
    int st = -1;

    public:
    void enqueue(int n) {
        if( st == MAX - 1) {
            cout<<"Queue overflow"<<endl;
        } else {
            st++;
            a[st] = n;
            cout<<n<<" is added to the queue"<< endl;
        }
    }
    int dequeue() {
        int i, v;
        if(st == -1) {
            cout<<"Queue underflow"<< endl;
        } else {
            v = a[0];
            for(i = 0; i<st; i++) {
                a[i] = a[i+1];
            }
            st--;
            return v;
        }
    }
    void display() {
        int i;
        for(i = 0; i<= st; i ++) {
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