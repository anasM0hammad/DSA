#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> arr = {1,9,3,0,18,5,2,4,10,7,12,6};
    unordered_set<int> set;

    for(auto i: arr){
        set.insert(i);
    }

    int max = 0;
    for(int i=0; i<arr.size(); i++){
        if(set.find(arr[i] - 1) == set.end()){
            int count = 0;
            int num = arr[i];
            while(set.find(num) != set.end()){
                count++;
                num++;
            }
            max = count > max ? count : max;
        }
    }

    cout<<max;

    return 0;
}