#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool cmp(string a, string b){
    if(a.size() != b.size()){
        return a.size() < b.size();
    }

    return a < b;
}

void findSubsets(vector<string> &subsets, string str, int i, string cur){
    if(i >= str.size()){
        subsets.push_back(cur);
        return;
    }

    findSubsets(subsets, str, i+1, cur);
    findSubsets(subsets, str, i+1, cur + str[i]);

    return;
}   

int main()
{
    string str = "abcd";
    vector<string> subsets;

    findSubsets(subsets, str, 0, "");

    sort(subsets.begin(), subsets.end(), cmp); 
    
    for(auto s: subsets){
        cout<<s<<" ";
    }
    return 0;
}