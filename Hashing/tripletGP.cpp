#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main()
{
    vector<int> arr = {1,16,4,16,64,16};
    int r = 4;

    unordered_map<int,int> left;
    unordered_map<int,int> right;

    for(auto i=1; i<arr.size(); i++){
        if(right.find(arr[i]) != right.end()){
            right[arr[i]]++;
        }
        else{
            right[arr[i]] = 1;
        }
    }
    int count = 0;

    for(auto i: arr){
        int l = i/r;
        int ri = i*r;

        int leftFreq = left.find(l) == left.end() ? 0 : left[l];
        int rightFreq = right.find(ri) == right.end() ? 0 : right[ri];

        count += leftFreq * rightFreq;

        if(left.find(i) != left.end()){
            left[i]++;
        }
        else{
            left[i] = 1;
        }

        if(right.find(i) != right.end() && right[i]){
            right[i]--;
        }
    }

    cout<<count<<endl;
    return 0;
}