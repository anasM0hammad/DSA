#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{   
   string ls = "hell_world";
   string ss = "lol";

   unordered_map<char, int> m;
   for(auto c: ss){
        if(m.find(c) != m.end()){
            m[c]++;
        }
        else{
            m[c] = 1;
        }
   }

   int i=0;
   int j=0;
   int count = ss.size();

   while(i<ls.size() && j<ls.size()){
        if(count == 0){
            if(m.find(ls[i]) != m.end() && m[ls[i]] == 0){
                break;
            }
            i++;
        }
        else{
            if(m.find(ls[j]) != m.end()){
                m[ls[j]]--;
                count--;
            }
            j++;
        }
   }

   cout<<(j-i)<<endl;
     
    return 0;
}