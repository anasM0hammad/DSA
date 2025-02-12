#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> arr = { 4,5,6,7,0,1,2,3 };
    int key = 2;

    int s = 0;
    int e = arr.size()-1;

    while(s <= e){
        int mid = (s+e)/2;

        if(arr[mid] == key){
            cout<<mid<<endl;
            return 0;
        }

        if(arr[mid] >= arr[s]){
            if(key < arr[mid] && key >= arr[s]){
                e = mid - 1;
            }
            else{
                s = mid+1;
            }
        }
        else if(arr[mid] <= arr[e]){
            if(key > arr[mid] && key <= arr[e]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    }

    return 0;
}