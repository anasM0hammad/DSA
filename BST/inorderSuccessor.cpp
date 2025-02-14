#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* createTree(vector<int> arr, int index){
    if(index >= arr.size()) return nullptr;

    if(arr[index] == -1) return nullptr;


    TreeNode* root = new TreeNode(arr[index]);
    root->left = createTree(arr, 2*index+1);
    root->right = createTree(arr, 2*index+2);

    return root;
}

void findSuccessor(TreeNode* root, int &cur, int target){
    if(!root) return;

    if(root->data <= target){
        findSuccessor(root->right, cur, target);
        return;
    }

    cur = min(cur, root->data);
    findSuccessor(root->left, cur, target);
    return;
}


int main(){
    vector<int> arr = {8,3,10,1,6,-1,14,-1,-1,4,7,-1,-1,13,-1};
    TreeNode* root = createTree(arr, 0);

    int cur = INT_MAX;
    int target = 10;
    findSuccessor(root, cur, target);

    cout<<cur<<endl;
    return 0;
}