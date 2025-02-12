#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


int main(){
    string str = "aabccbcd";
    queue<char> q;
    unordered_map<char, int> m;

    for(auto i: str){
        if(m.find(i) == m.end()){
            m[i] = 1;
            q.push(i);
        }
        else{
            m[i]++;
        }

        while(!q.empty() && m[q.front()] > 1){
            q.pop();
        }

        if(q.empty()){
            cout<<-1<<" ";
        }
        else{
            cout<<q.front()<<" ";
        }
    }
   
    return 0;
}