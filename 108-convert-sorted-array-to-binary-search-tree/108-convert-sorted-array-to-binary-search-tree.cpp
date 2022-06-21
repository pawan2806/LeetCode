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
    TreeNode* helper(vector<int>& nums, int l, int r){
        if(l>r){
            return NULL;
        }
        int mid=(l+r)/2;
        int val=nums[mid];
        TreeNode* root=new TreeNode(val);
        root->right=helper(nums, mid+1, r);
        root->left=helper(nums, l, mid-1);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(nums, 0, nums.size()-1);
    }
};