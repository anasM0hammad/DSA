#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isRedundant(string str){
    stack<char> s;

    for(auto i: str){
        if(i == '('){
            s.push('(');
        }
        else if(i == ')'){
            bool isOp = false;
            while(!s.empty() && s.top() != '('){
                isOp = true;
                s.pop();
            }
            s.pop();

            if(!isOp) return true;
        }
        else if(i == '+' || i == '-' || i == '*' || i == '/'){
            s.push(i);
        }
    }

    return false;
}

int main(){
    string str = "(a+(b)/c)";

    bool ans =  isRedundant(str);
    cout<<boolalpha<<ans;
    return 0;
}