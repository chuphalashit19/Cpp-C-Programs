#include<bits/stdc++.h>
#include<stack>
#include<ctype.h>

using namespace std;

int Evaluate(int op1, int op2, char exp){
    if (exp == '+')
        return op1+op2;
    else if(exp == '-')
        return op1-op2;
    else if(exp == '*')
        return op1*op2;
    else if(exp == '/')
        return op1/op2;
    return -1;
}

char EvaluatePostfix(string exp){
    stack <int> S;
    for(int i=0; i<exp.length(); i++){
        if(isdigit(exp[i])){
            int val = exp[i] - '0';
            S.push(val);
        }
        else{
            int op2 = S.top(); S.pop();
            int op1 = S.top(); S.pop();
            int res = Evaluate(op1, op2, exp[i]);
            S.push(res);
        }
    }
    return S.top();
}

int EvaluatePrefix(string exp){
    stack<int> S;
    for(int i = exp.length()-1; i>=0; i--){
        if(isdigit(exp[i])){
            int val = exp[i] - '0';
            S.push(val);
        }
        else{
            int op1 = S.top(); S.pop();
            int op2 = S.top(); S.pop();
            int res = Evaluate(op1, op2, exp[i]);
            S.push(res);
        }
    }
    return S.top();
}


int main(){
    int n;
    string exp;
    cout << "Choose:" << endl << "1. Postfix" << endl << "2. Prefix" << endl;
    cout << "Your choice: ";
    cin >> n;
    if(n == 1){
        cout << "Enter the postfix expression: ";
        cin.ignore();
        getline(cin , exp);
        int result = EvaluatePostfix(exp);
        cout << "Answer:" << result;
    }
    else if(n == 2){
        cout << "Enter the prefix expression: ";
        cin.ignore();
        getline(cin , exp);
        int result = EvaluatePrefix(exp);
        cout << "Answer:" << result << endl << endl;
    }
}
