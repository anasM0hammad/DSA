#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

void findPermutation(vector<string> &ans, string str, int index, string cur){
    // base case
    if(index == str.size()){
        ans.push_back(cur);
        return;
    }

    for(int i=index; i<str.size(); i++){
        swap(str[index], str[i]);
        findPermutation(ans, str, index+1, cur+str[index]);
    }
}

int main()
{
    string str = "abc";
    vector<string> ans;

    findPermutation(ans, str, 0, "");

    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}