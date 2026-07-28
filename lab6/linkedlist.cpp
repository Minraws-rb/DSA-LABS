#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
     Node(int val) {
         data = val;
         next = NULL;
     }
};

class List {
    public:
    Node* head;
    Node* tail;
    
    List() {
        head = tail = NULL;
    }
    
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void pop_front() {
        Node* temp = head;
        if(head == NULL) {
            cout<<"empty ll"<<endl;
            return;
        }
        else if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    void pop_back() {
        if(head == NULL) {
            cout<<"Empty ll"<<endl;
            return;
        }
        else if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
        
    }
    void display() {
        if(head == NULL) {
            cout<<"empty LL"<<endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
    
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(0);
    ll.push_back(-1);
    ll.display();
    ll.pop_front();
    ll.pop_front();
    ll.display();
    ll.pop_back();
    ll.display();

    return 0;
}