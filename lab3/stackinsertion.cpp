#include<iostream>
using namespace std;
#define MAX 5
class stack {
    private:
     int arr[MAX];
     int top = -1;

    public:
     void push(int n){
        if(top == MAX -1){
            cout<<"StackOverflow"<<endl;
        } else {
            top++;
            arr[top] = n;
            cout<<n<<"is added to stack top"<<endl;
        }
     }
     int pop() {
        if(top == -1) {
            cout<<"StackUnderflow"<<endl;
        } else {
            top--;
            return arr[top+1];
        }
     }

     void display() {
        int i;
        for(i = top; i>= 0; i--) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
     }
};

int main() {
    stack s;
    s.push(20);
    s.push(10);
    s.push(30);
    s.display();
    s.pop();
    s.display();
    return 0;
}