#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    string input;
    getline(input, cin);

    stringstream ss(input);
    vector<string> tokens;
    string token;
    while(getline(ss, token, ' ')){
        tokens.push_back(token);
    }
     
    return 0;
}