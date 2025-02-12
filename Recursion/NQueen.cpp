#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPossible(vector<vector<int>> board, int r, int c, int n){
    int i=r;
    int j=c;

    while(i >= 0){
        if(board[i][c] == 1){
            return false;
        }
        i--;
    }

    i=r;
    while(i < n){
        if(board[i][c] == 1){
            return false;
        }
        i++;
    }

    i = r;
    while(j >= 0){
        if(board[r][j] == 1){
            return false;
        }
        j--;
    }

    j = c;
    while(j < n){
        if(board[r][j] == 1){
            return false;
        }
        j++;
    }

    i=r;
    j=c;

    while(i >= 0 && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        j--;
        i--;
    }

    i=r;
    j=c;

    while(i >= 0 && j < n){
        if(board[i][j] == 1){
            return false;
        }
        j++;
        i--;
    }

    i=r;
    j=c;

    while(i < n && j < n){
        if(board[i][j] == 1){
            return false;
        }
        j++;
        i++;
    }

    i=r;
    j=c;

    while(i < n && j >= 0){
        if(board[i][j] == 1){
            return false;
        }
        j--;
        i++;
    }

    return true;

}

bool findNQueen(vector<vector<int>> &board, int r, int n){
    if(r >= n) return true;
    
    for(int i=0; i<n; i++){
        bool place = isPossible(board, r, i, n);
        if(place){
            board[r][i] = 1;
            if(findNQueen(board, r+1, n)){
                return true;
            }
            board[r][i] = 0;
        }
    }
    return false;
}

int main()
{
   int n = 4;
   vector<vector<int>> board;

   for(int i=0; i<n; i++){
        vector<int> temp(n,0);
        board.push_back(temp);
   }

    bool ans = findNQueen(board, 0, n);

    for(auto x: board){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}