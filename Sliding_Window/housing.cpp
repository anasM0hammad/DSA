#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
    int k=8;

    int i=0;
    int j=0;
    int sum = 0;
    int count = 0;

   while(i < arr.size() && j < arr.size()){
        if(arr[j] + sum == k){
            count++;
            sum -= arr[i];
            i++;
            j++;
        }
        else if(arr[j] + sum < k){
            sum += arr[j];
            j++;
        }
        else{
            sum -= arr[i];
            i++;
        }
   }

   cout<<count<<endl;
     
    return 0;
}