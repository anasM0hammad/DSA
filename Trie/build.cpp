#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
    public:
        char key;
        bool isTerminal;
        unordered_map<char, Node*> children;

        Node(char ch){
            this->key = ch;
            this->isTerminal = false;
        }
};

void insertWord(Node* root, string word, int index){
    if(index >= word.size()){
        root->isTerminal = true;
        return;
    };

    if(root->children.find(word[index]) == root->children.end()){
        Node* newNode = new Node(word[index]);
        root->children[word[index]] = newNode;
    }
    insertWord(root->children[word[index]], word, index+1);

    return;
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
    vector<string> words = { "apple", "ape", "mango", "news", "new" };
    Node* root = new Node('\0');

    for(auto i: words){
        insertWord(root, i, 0);
    }

    cout<<boolalpha<<isExist(root, "news", 0);

    return 0;
}