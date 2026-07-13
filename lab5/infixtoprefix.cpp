#include<bits/stdc++.h>
using namespace std;

int precedence(char s){
    if(s =='+' || s == '-') return 1;
    else if(s=='*' || s == '/' || s == '^' || s == '%') return 2;
    return 0;
    
}

char topostfix(string exp){
    int i, j = 0;
    char postexp[100];
    stack<char> s;
    for(i = 0 ; i < exp.length() ; i++) {
        if(isalnum(exp[i])){
            postexp[j] = exp[i];
            j++;
            cout<<"inserting alphanum "<<exp[i]<<endl;
        }
        else if(exp[i] == '(') {
            s.push(exp[i]);
            cout<<"( pushing " <<endl;
        }
        else if(exp[i] == ')') {
             while(s.top() != '(' && !s.empty()){
                cout<<"poppping between ("<<s.top()<<" )"<<endl;
                 postexp[j] = s.top();
                 s.pop();
                 j++;
             }
             s.pop();
             cout<<" popping )"<<endl;
             j++;
        }
        else if(!s.empty() && precedence(exp[i]) <= precedence(s.top())) {
            postexp[j] = s.top();
            cout<<"pop "<<s.top()<<" ";
            s.pop();
            j++;
            s.push(exp[i]);
            cout<<"Push"<<s.top()<<endl;
            
        }
        else {
            s.push(exp[i]);
            cout<<" else wala push "<<exp[i]<<endl;
        }
    }
    while(!s.empty()){
        cout<<"all remaining "<<s.top()<<endl;
        postexp[j] = s.top();
        j++;
        s.pop();
    }
    for(i = 0; i< exp.length(); i++){
        cout<<postexp[i];
    }
    cout<<endl;
    return *postexp;
}
int main() {
    string exp ;
    cout<<"Enter the expression"<<endl;
    cin>>exp; 
    cout<<endl;
    cout<<" "<< topostfix(exp)<<endl;
    return 0;
}



