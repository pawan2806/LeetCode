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
class BSTIterator {
public:
    stack<TreeNode *> myStack;

        BSTIterator(TreeNode *root) {
            pushAll(root);
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !myStack.empty();
        }

        /** @return the next smallest number */
        int next() {
            TreeNode *tmpNode = myStack.top();
            myStack.pop();
            pushAll(tmpNode->right);
            return tmpNode->val;
        }

    private:
        void pushAll(TreeNode *node) {
            while (node != NULL) {
                myStack.push(node);
                node = node->left;
            }
        }
//      map<int, TreeNode*> m;
//  TreeNode *it=NULL;
//  map<int, TreeNode*>::iterator itr;
// void in(TreeNode *A,  map<int, TreeNode*> &m){
//     if(!A){
//         return;
//     }
//     in(A->left, m);
//     int x=A->val;
//     m[x]=A;
//     in(A->right, m);
    
// }
//     BSTIterator(TreeNode* root) {
//         it=root;
//     m.clear();
//     in(root, m);
//     itr=m.begin();
//     }
    
//     int next() {
//         int x=itr->first;
//     itr++;
//     return x;
//     }
    
//     bool hasNext() {
//         if(itr==m.end()){
//         return false;
//     }
    
//     return true;
//     }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */