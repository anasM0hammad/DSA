#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string str){
    stack<char> s;

    for(auto i: str){
        if(i == '('){
            s.push('(');
        }
        else if(i == ')'){
            if(s.empty()) return false;

            s.pop();
        }
    }

    return s.empty();
}

int main(){
    string str = "((a+b)*x-d)";

    bool ans =  isValid(str);
    cout<<boolalpha<<ans;
    return 0;
}