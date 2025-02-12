#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// void swapX(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

int main()
{
    vector<int> arr = { 10,11,5,4,3,2,1 }; 
    unordered_map<int,int> m;

    for(int i=0; i<arr.size(); i++){
        m[arr[i]] = i;
    }

    vector<int> newArr(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());

    int count = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != newArr[i]){
            count++;
            int temp = newArr[i];
            newArr[i] = arr[i];
            newArr[m[arr[i]]] = temp;

            m[temp] = m[arr[i]];
            m[arr[i]] = i;
        }
    }
    cout<<count<<endl;
    return 0;
}