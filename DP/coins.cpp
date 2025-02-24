#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

int helper(vector<int> coins, int i, int money, unordered_map<int,int> & m){
    if(i >= coins.size() || money < 0){
        return 30;
    }

    if(money == 0){
        return 0;
    }

    if(m.find(money) != m.end()){
        return m[money];
    }

    int a = helper(coins, i, money-coins[i], m) + 1;
    int b = helper(coins, i+1, money-coins[i], m) + 1;
    int c = helper(coins, i+1, money, m);

    int ans = min(a, min(b,c));
    m[money] = ans;

    return ans;
}

int findMin(vector<int> coins, int money){
    int index = 0;
    unordered_map<int,int> memoise;

    return helper(coins, index, money, memoise);
}

int main()
{
    vector<int> coins = {1,3,7,10};
    int money = 15;

    int ans = findMin(coins, money);
    cout<<ans<<endl;

    return 0;
}