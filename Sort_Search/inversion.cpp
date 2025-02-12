#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int s, int mid, int e, int &count){
    int i = s;
    int j = mid+1;

    vector<int> temp;
    while(i <= mid && j <= e){
        if(arr[i] > arr[j]){
            while(arr[i] > arr[j] && j <= e){
                temp.push_back(arr[j]);
                j++;
            }
            count += (j - mid-1);

            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }

    while(j <= e){
        temp.push_back(arr[j]);
        j++;
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
        count += (e - mid);
    }

    int x = 0;
    for(int i=s; i<=e; i++){
        arr[i] = temp[x];
        x++;
    }

    return;

}

void countInversion(vector<int>& arr, int s, int e, int &count){
    if(s == e) return;

    int mid = (s+e)/2;
    countInversion(arr, s, mid, count);
    countInversion(arr, mid+1, e, count);

    merge(arr, s, mid, e, count);
}

int main()
{
    vector<int> arr = { 0, 5, 2, 3, 1 };
    int count = 0;
    countInversion(arr, 0, arr.size()-1, count);
    cout<<count<<endl;
    return 0;
}