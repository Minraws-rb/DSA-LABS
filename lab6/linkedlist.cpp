#include <iostream>
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
    private:
    Node* head;
    Node* tail;
    public:
    List() {
        head = tail = NULL;
    }
    
    void push_first(int val) {
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
        if(head == NULL) {
            cout<<"Linked list doesnt exist!!"<<endl;
        }
        else {
        Node* ptr = head;
        head = ptr->next; 
        ptr->next = NULL; 
        
        delete ptr;
     }
    }
    
    void pop_back() {
        Node* temp = head;
        if(head == NULL) {
            cout<<"Linked list is empty!!"<<endl;
        }
        else {
            while(temp->next != tail) {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
        
    }
    
    void display() {
        Node* temp = head;
        while(temp != NULL) {
            cout<< temp->data << "->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    List ll;
    ll.push_first(1);
    ll.push_first(2);
    ll.push_first(3);
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