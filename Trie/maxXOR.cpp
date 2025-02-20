#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
    public:
        char key;
        bool isTerminal;
        int index;
        unordered_map<char, Node*> children;

        Node(char ch){
            this->key = ch;
            this->isTerminal = false;
            this->index = -1;
        }
};

void insertWord(string word, int i, Node* trie, int index){
    if(i >= word.size()){
        trie->isTerminal = true;
        trie->index = index;
        return;
    }

    if(trie->children.find(word[i]) == trie->children.end()){
        Node* root = new Node(word[i]);
        trie->children[word[i]] = root;
    }

    insertWord(word, i+1, trie->children[word[i]], index);
}

bool isExist(Node* root, string word, int i){
    if(i >= word.size()) return root->isTerminal;

    if(root->children.find(word[i]) == root->children.end()){
        return false;
    }
    return isExist(root->children[word[i]], word, i+1);
}

string findBits(int number){
    string ans = "00000000000000000000000000000000";
    int index = 31;

    while(number){
        int bit = number & 1;
        bit == 1 ? ans[index] = '1' : ans[index] = '0';
        number = number >> 1;
        index--;
    }

    return ans;
}

int findVal(string bits){
    int number = 0;
    int multiplier = 1;
    for(int i=31; i>=0; i--){
        if(bits[i] == '1'){
            number += multiplier;
        }
        multiplier *= 2;
    }
    return number;
}

int main()
{
    vector<int> arr = { 3,2,5,8,10,25 };
    Node* trie = new Node('\n');

    for(auto i: arr){
        string bits = findBits(i);
        insertWord(bits, 0, trie, i);
    }

    pair<int,int> ans;
    int max = -1;
    for(int i: arr){
        string cur = "0000000000000000000000000000000";
        int x = 0;
        string bits = findBits(i);
        Node* root = trie;
        for(int j=0; j<32; j++){
            char bit = bits[j];
            if(bit == '1'){
                if(root->children.find('0') != root->children.end()){
                    cur[x] = '1';
                    root = root->children['0'];
                }
                else{
                    cur[x] = '0';
                    root = root->children['1'];
                }
            }
            else{
                if(root->children.find('1') != root->children.end()){
                   cur[x] = '1';
                   root = root->children['1'];
                }
                else{
                    cur[x] = '0';
                    root = root->children['0'];
                }
            }
            x++;
        }
        int number = root->index;
        // cout<<cur<<" ";
        int curVal = findVal(cur);
        if(max < curVal){
            ans = { i, number };
            max = curVal;
        }
    }
    cout<<ans.first<<" "<<ans.second<<" "<<max;
    return 0;
}