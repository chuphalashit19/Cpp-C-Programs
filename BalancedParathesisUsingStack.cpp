#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool CheckPair(char open,char close)
{
	if(open == '(' && close == ')') return true;
	else if(open == '{' && close == '}') return true;
	else if(open == '[' && close == ']') return true;
	return false;
}

bool CheckBalancedParanthesis(string exp){
    stack<char> s;
    for(int i=0; i<exp.length(); i++){
       if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            s.push(exp[i]);
       else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(s.empty() || !CheckPair(s.top(),exp[i]))
                return false;
            else
                s.pop();
       }
    }
    return s.empty() ? true:false;
}

int main(){
    string exp;
    cout << "Enter the expression: ";
    getline(cin, exp);
    cout << endl;
    if(CheckBalancedParanthesis(exp))
        cout << "Balanced!!" << endl << endl;
    else
        cout << "Not Balanced!!" << endl << endl;
}
