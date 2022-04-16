#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *get_tree(string data){
    if(data.length() == 2) return NULL;
    queue<string> arr;
    string temp = "";
    for(int i=1;i<data.length()-1;i++){
        if(data[i] == ','){
            arr.push(temp);
            temp = "";
        }
        else{
            temp += data[i];
        }
    }
    arr.push(temp);
    
    TreeNode *ans = new TreeNode(stoi(arr.front()));
    arr.pop();
    queue<TreeNode *> Q;
    Q.push(ans);

    while(!Q.empty() && !arr.empty()){
        TreeNode *root = Q.front(); Q.pop();
        string l = arr.front(); arr.pop();
        string r;
        if(arr.size() > 0){
            r = arr.front(); arr.pop();
        }
        else{
            r = "null";
        }
        if(l == "null"){
            root->left = NULL;
        }
        else{
            root->left = new TreeNode(stoi(l));
            Q.push(root->left);
        }
        if(r == "null"){
            root->right = NULL;
        }
        else{
            root->right = new TreeNode(stoi(r));
            Q.push(root->right);
        }
    }

    return ans;
}

class Solution {
public:
    vector<int> ans;
    void f(TreeNode *root){
        if(root == NULL) return;
        f(root->left);
        f(root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        f(root);
        return ans;
    }
};
// @lc code=end

int main(){
    string data;
    cin>>data;
    TreeNode *root = get_tree(data);
    Solution test;
    vector<int> res = test.postorderTraversal(root);
    for(auto &item: res){
        cout<<item<<' ';
    }
    cout<<'\n';

    return 0;
}