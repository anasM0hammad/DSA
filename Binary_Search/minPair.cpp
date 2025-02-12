#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    vector<int> arr1 = { -1, 5, 10, 20, 3 };
    vector<int> arr2 = { 26, 134, 135, 15, 21, 16, 37, 17 };

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i=0;
    int j=0;
    int ans = INT_MAX;

    while(i < arr1.size() && j < arr2.size()){
        ans = min(ans, abs(arr1[i] - arr2[j]));

        if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    cout<<ans<<endl;
   
    return 0;
}