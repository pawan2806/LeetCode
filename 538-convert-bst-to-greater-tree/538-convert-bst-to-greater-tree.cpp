/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> ans;
    void helper(TreeNode *root)
    {
        if (!root)
        {
            return ;
        }
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
        
    }
    
    void helper2(TreeNode* root){
        if (!root)
        {
            return ;
        }
        
        int i=0, sum=0;
        while(i<ans.size() && ans[i]<root->val){
            i++;
        }
        for(;i<ans.size();i++){
            sum+=ans[i];
        }
        root->val=sum;
        helper2(root->right);
        helper2(root->left);
        
    }
    TreeNode* convertBST(TreeNode *root)
    {
        
        helper(root);
        helper2(root);
        return root;
    }
};