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

TreeNode* createTree(vector<int> arr, int s, int e){
    if(s > e) return nullptr;

    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = createTree(arr, s, mid-1);
    root->right = createTree(arr, mid+1, e);

    return root;
}

pair<TreeNode*, TreeNode*> createLL(TreeNode* root){
    //base case
    if(!root) return { nullptr, nullptr };
    if(!root->left && !root->right){
        return { root, root };
    }

    pair<TreeNode*, TreeNode*> left = createLL(root->left);
    pair<TreeNode*, TreeNode*> right = createLL(root->right);

    left.second->right = root;
    root->left = nullptr;
    root->right = right.first;
    return { left.first, right.second };
}

void printLL(TreeNode* head){
    while(head){
        cout<<head->data<<" ";
        head = head->right;
    }
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    TreeNode* root = createTree(arr, 0, arr.size()-1);

    TreeNode* LL = createLL(root).first;

    printLL(LL);

    return 0;
}