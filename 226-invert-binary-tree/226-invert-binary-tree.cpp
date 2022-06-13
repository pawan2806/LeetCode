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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        queue<TreeNode*> q;
        TreeNode* temp=root;
        q.push(temp);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* use=q.front();
                q.pop();
                temp=use->left;
                use->left=use->right;
                use->right=temp;
                
                if(use->left){
                    q.push(use->left);
                }
                if(use->right){
                    q.push(use->right);
                }
                
            }
        }
        return root;
    }
};