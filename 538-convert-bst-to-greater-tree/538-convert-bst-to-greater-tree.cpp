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
    int index=0;
    unordered_map<int,int> m;
    void helper(TreeNode *root)
    {
        if (!root)
        {
            return ;
        }
        helper(root->left);
        m[root->val]=index;
        index++;
        ans.push_back(root->val);
        helper(root->right);
        
    }
    
    void helper2(TreeNode* root){
        if (!root)
        {
            return ;
        }
        int gg=m[root->val];
        root->val=root->val+ans[ans.size()-1]-ans[gg];
        
        helper2(root->right);
        helper2(root->left);
        
    }
    TreeNode* convertBST(TreeNode *root)
    {
        
        helper(root);
        for(int i=1;i<ans.size();i++){
            ans[i]=ans[i]+ans[i-1];
        }
        helper2(root);
        return root;
    }
};