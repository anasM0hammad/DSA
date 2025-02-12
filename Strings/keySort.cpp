#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
   int size = 3;
   vector<string> str = {"92 022", "82 12", "77 13"};
  
    int key = 2;

    vector<string> ans;
    vector<pair<int,int>> sortedKeys;

   for(int i=0; i<str.size(); i++){
        stringstream ss(str[i]);
        string token;
        int x = 1;
        while(getline(ss, token, ' ')){
            if(x == key){
                sortedKeys.push_back({stoi(token), i});
            }
            x++;
        }
   }

    sort(sortedKeys.begin(), sortedKeys.end());
    for(int i=0; i<str.size(); i++){
        int index = sortedKeys[i].second;
        ans.push_back(str[index]);
        cout<<str[index]<<" ";
    }
    return 0;
}