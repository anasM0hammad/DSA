#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, string> m;

void generateMsg(vector<string> &ans, string str, int index, string s){
    // base case
    if(index == str.size()){
        ans.push_back(s);
        return;
    }

    char c = str[index];
    for(auto x: m[c]){
        generateMsg(ans, str, index+1, s+x);
    }

    return;
}

int main()
{
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    string str = "23";
    vector<string> ans;

    generateMsg(ans, str, 0, "");

    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}