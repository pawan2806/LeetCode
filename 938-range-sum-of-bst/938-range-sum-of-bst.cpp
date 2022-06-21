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
    int sum=0;
    void util(TreeNode *root, int low, int high){
        if(!root){
            return ;
        }
        
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
        
       util(root->left, low, high);
        util(root->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)return 0;
        
        if(root->val <low)
            return rangeSumBST(root->right,low,high);
        if(root->val > high)
            return rangeSumBST(root->left,low,high);
        
        return (root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high));
        
    }
//     int rangeSumBST(TreeNode* root, int low, int high) {
//         util(root, low, high);
        
//         return sum;
//     }
};