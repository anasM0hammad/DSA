#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> mountain = { 5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4 }; 

    int max = -1;

    for(int i=0; i<mountain.size(); i++){
        if(i != 0 && i != mountain.size() - 1){
            if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]){
                // count left
                int count = 0;
                int j=i-1;
                while(j >= 0 && mountain[j] < mountain[j+1]){
                    count++;
                    j--;
                }

                int  k = i;
                while(k < mountain.size() && mountain[k] > mountain[k+1]){
                    count++;
                    k++;
                }

                if(count + 1 > max) max = count+1;
            }
        }
    }
    cout<<max;

    return 0;
}