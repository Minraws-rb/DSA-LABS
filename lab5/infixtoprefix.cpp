#include<bits/stdc++.h>
using namespace std;

int precedence(char s){
    if(s =='+' || s == '-') return 1;
    else if(s=='*' || s == '/' || s == '^' || s == '%') return 2;
    return 0;
    
}

void toprefix(string exp, char preexp[]){
    int i, j = 0;
    stack<char> s;

    // reverse expression
    reverse(exp.begin(), exp.end());

    // swap brackets
    for(i = 0; i < exp.length(); i++){
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
    }

    for(i = 0 ; i < exp.length() ; i++) {

        if(isalnum(exp[i])){
            preexp[j] = exp[i];
            j++;
            cout<<"inserting alphanum "<<exp[i]<<endl;
        }

        else if(exp[i] == '(') {
            s.push(exp[i]);
            cout<<"( pushing "<<endl;
        }

        else if(exp[i] == ')') {

            while(!s.empty() && s.top() != '('){
                cout<<"poppping between ( "<<s.top()<<" )"<<endl;
                preexp[j] = s.top();
                s.pop();
                j++;
            }

            s.pop();
            cout<<" popping )"<<endl;
        }

        else {

            while(!s.empty() && precedence(exp[i]) <= precedence(s.top())) {

                preexp[j] = s.top();
                cout<<"pop "<<s.top()<<endl;
                s.pop();
                j++;
            }

            s.push(exp[i]);
            cout<<" else push "<<exp[i]<<endl;
        }
    }

    while(!s.empty()){
        cout<<"all remaining "<<s.top()<<endl;
        preexp[j] = s.top();
        j++;
        s.pop();
    }

    preexp[j]='\0';

    // reverse postfix result to prefix
    reverse(preexp, preexp+j);
}

int main() {

    string exp ="a+b*c+(d-e)/f";
    char preexp[100];

    cout<<"Enter the expression"<<endl;
    cout<<endl;

    toprefix(exp, preexp);

    cout<<preexp<<endl;

    return 0;
}