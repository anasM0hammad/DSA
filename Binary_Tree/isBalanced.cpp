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

void levelOrder(TreeNode* root){
    if(!root) return;

    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        
        if(temp){
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            cout<<temp->data<<" ";
        }
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
    }
}

pair<int,int> isBalanced(TreeNode* root){
    // base case
    if(!root) return { true,0 };

    pair<int,int> left = isBalanced(root->left);
    pair<int,int> right = isBalanced(root->right);
    int h = abs(left.second - right.second);

    if(left.first && right.first && h <= 1){
        return { true, max(left.second, right.second) + 1 };
    }
    return { false, max(left.second, right.second) + 1 };
}

int main(){
    vector<int> arr = {1,2,3,4,5,-1,6,-1,-1,7};
    TreeNode* root = createTree(arr, 0);
    cout<<boolalpha<<isBalanced(root).first;
    return 0;
}