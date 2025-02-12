#include <iostream>
#include <vector>
using namespace std;

void generateP(vector<string> &p, int open, int close, string cur){
    // base case
    if(open < 0) return;
    if(close < 0) return;

    if(open == 0 && close == 0){
        p.push_back(cur);
        return;
    }


    if(open == close){
        generateP(p, open-1, close, cur+"(");
    }
    else if(open < close){
        generateP(p, open-1, close, cur+"(");
        generateP(p, open, close-1, cur+")");
    }
    return;
}

int main()
{
    int n = 3;
    vector<string> p;
    generateP(p, n, n, "");

    for(auto x: p){
        cout<<x<<" ";
    }

    return 0;
}