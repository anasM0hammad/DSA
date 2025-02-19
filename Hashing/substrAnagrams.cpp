#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> getHash(string str){
    vector<int> ans(26,0);
    for(auto c: str){
        int x = c - 'a';
        ans[x]++;
    }
    return ans;
}

int NC2(int n){
    int ans = 1;
    for(int i=n; i>2; i--){
        ans *= i;
    }

    int div = 1;
    for(int i=n-2; i>0; i--){
        div *= i;
    }

    return ans/div;
}

int main()
{
    string input = "abba";

   map<vector<int>, int> m;

    for(int i=0; i<input.size(); i++){
        for(int j=i+1; j<input.size(); j++){
            string sub = input.substr(i,j+1);
            vector<int> hash = getHash(sub);
            if(m.find(hash) != m.end()){
                m[hash]++;
            }
            else{
                m[hash] = 1;
            }
        }
    }

    int count = 0;
    for(auto i=m.begin(); i != m.end(); i++){
        if(i->second > 1){
            count += NC2(i->second);
        }
    }

    cout<<count<<endl;
    return 0;
}