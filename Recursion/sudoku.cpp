#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPossible(int arr[][9], int r, int c, int value){
    for(int i=0; i<9; i++){
        if(arr[i][c] == value) return false;
        if(arr[r][i] == value) return false;
    }

    int x = (r/3)*3;
    int y = (c/3)*3;

    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            if(arr[i][j] == value) return false;
        }
    }

    return true;
}

bool solveSudoku(int arr[][9], int r, int c){
    if(r >= 9) return true;
    if(c >= 9) return solveSudoku(arr, r+1, 0);

    if(arr[r][c] != 0){
        return solveSudoku(arr, r, c+1);
    }

    for(int i=1; i<=9; i++){
        if(isPossible(arr, r, c, i)){
            arr[r][c] = i;
            if(solveSudoku(arr, r, c+1)){
                return true;
            }
            arr[r][c] = 0;
        }
    }

    return false;
}

int main()
{
   int arr[9][9] = {{5,3,0,0,7,0,0,0,0},
                    {6,0,0,1,9,5,0,0,0},
                    {0,9,8,0,0,0,0,6,0},
                    {8,0,0,0,6,0,0,0,3},
                    {4,0,0,8,0,3,0,0,1},
                    {7,0,0,0,2,0,0,0,6},
                    {0,6,0,0,0,0,2,8,0},
                    {0,0,0,4,1,9,0,0,5},
                    {0,0,0,0,8,0,0,7,0},
                };

    solveSudoku(arr, 0, 0);

    for(auto i=0; i<9; i++){
        for(auto j=0; j<9; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}