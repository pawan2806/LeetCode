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
    int i=1, gg=-1;
    void helper(TreeNode* root, int k) {
        if(!root || i>k){
            return;
        }
        helper(root->left, k);
        if(i==k){
            gg=root->val;
        }
        i++;
        helper(root->right, k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return gg;
        
    }
};