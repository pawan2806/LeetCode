/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ans;
    void inorder(TreeNode* root){
        if(!root){
            return ;
        }
        inorder(root->left);
        ans.push_back(root);
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        int n=ans.size();
        if(n==0){
            return root;
        }
        
        for(int i=0;i<n;i++){
            if(i+1<n){
                ans[i]->left=NULL;
                ans[i]->right=ans[i+1];
            } else {
                ans[i]->left=NULL;
                ans[i]->right=NULL;
            }
            cout<<ans[i]->val<<endl;
        }
        return ans[0];
    }
};