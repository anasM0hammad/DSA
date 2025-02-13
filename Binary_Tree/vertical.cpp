#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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

void verticalPrint(TreeNode* root, unordered_map<int, vector<int>> &m, int yAxis){
    if(!root) return;

    if(m.find(yAxis) != m.end()){
        m[yAxis].push_back(root->data);
    }
    else{
        vector<int> temp = { root->data };
        m[yAxis] = temp;
    }

    verticalPrint(root->left, m, yAxis-1);
    verticalPrint(root->right, m ,yAxis+1);
    return;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,-1,-1,-1,-1,-1,8,-1,9};
    TreeNode* root = createTree(arr, 0);
    unordered_map<int, vector<int>> m;
    verticalPrint(root, m, 0);
    
    for(auto i: m){
        for(auto x: i.second){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}