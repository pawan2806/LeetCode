/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
     Node* connect(Node* root) 
    {
         if(!root) return nullptr;
        queue<Node*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            int size = queue.size();
            Node *node = NULL;
            while(size--){
                auto curr = queue.front();
                if(node != NULL){
                    node->next = curr;
                }
                queue.pop();
                node = curr;
                if(curr->left) queue.push(curr->left);
                if(curr->right) queue.push(curr->right);
            }
            node->next = NULL;
        }
        return root;
    }
};