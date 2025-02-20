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

int main()
{
    vector<string> words = { "cute cat", "ttle", "cat", "quick", "big" };
    string s = "little cute cat loves to code in cpp, java and python";

    Node* trie = new Node('\0');
    int idx = 0;
    for(auto word: words){
        insertWord(word, 0, trie, idx);
        idx++;
    }

    for(int i=0; i<s.size(); i++){
        if(trie->children.find(s[i]) != trie->children.end()){
            int j=i;
            Node* root = trie;
            while(root && root->children.find(s[j]) != root->children.end() && j < s.size()){
                root = root->children[s[j]];

                if(root->isTerminal){
                    cout<<root->index<<" ";
                }
                j++;
            }
        }
    }

    return 0;
}