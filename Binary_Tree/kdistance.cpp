#include <iostream>
#include <vector>
#include <unordered_map>
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

void KNodeSubtree(TreeNode* root, int k){
    if(!root) return;

    if(k == 0){
        cout<<root->data<<" ";
        return;
    }

    KNodeSubtree(root->left, k-1);
    KNodeSubtree(root->right, k-1);
    return;
}

pair<bool, int> findTargetAndPath(TreeNode* root, unordered_map<int,int>& m, int target, int k){
    if(!root) return { false, -1};

    if(root->data == target){
        m[target] = 0;
        KNodeSubtree(root, k);
        return {true, 0};
    }

    pair<bool,int> left = findTargetAndPath(root->left, m, target, k);
    pair<bool, int> right = findTargetAndPath(root->right, m, target, k);

    if(left.first){
        m[root->data] = left.second + 1;
        return { true, left.second+1 };
    }

    if(right.first){
        m[root->data] = right.second + 1;
        return { true, right.second+1 };
    }

    return { false, -1};
}

void KNodeOutside(TreeNode* root, unordered_map<int,int> m, int k, int cur){
    if(!root) return;

    if(m.find(root->data) != m.end()){
        if(m[root->data] == 0) return;  // target node

        if(m[root->data] == k){
            cout<<root->data<<" ";
        }

        KNodeOutside(root->left, m, k, m[root->data]+1);
        KNodeOutside(root->right, m ,k, m[root->data]+1);
    }
    else{
        if(cur == k){
            cout<<root->data<<" ";
            return;
        }

        KNodeOutside(root->left, m, k, cur+1);
        KNodeOutside(root->right, m ,k, cur+1);
    }
}


int main(){
    vector<int> arr = {1,2,3,4,5,-1,6,-1,-1,7,8,-1,-1,-1,-1,-1,-1,-1,-1,9,10};
    TreeNode* root = createTree(arr, 0);
    unordered_map<int,int> m;   
    int target = 5;
    int k=2;

    findTargetAndPath(root, m, target, k);
    KNodeOutside(root, m, k, m[root->data]);
    return 0;
}