#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{   
    string s = "prateekbhaiya";
    
    int i=0;
    int j=0;

    int count = 0;
    int ans = -1;
    int curString = 1;
    unordered_map<char, int> m;

    while(i< s.size() && j < s.size()){
        if(m.find(s[j]) != m.end() && m[s[j]] == curString){
            ans = max(ans, count);
            curString++;
            while(s[i] != s[j]){
                i++;
                count--;
            }
            i++;
            count--;
        }
        else{
            m[s[j]] = curString;
            count++;
            j++;
        }
    }   
    cout<<ans<<endl;
     
    return 0;
}