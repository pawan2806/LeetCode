/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        typedef pair<int, ListNode*> pd;
    struct myComp
    {
        constexpr bool operator()(pair<int, ListNode*>
            const &a, pair<int, ListNode*>
            const &b)
        const noexcept
        {
            return a.first > b.first;
        }
    };
    ListNode* mergeKLists(vector<ListNode*> &lists)
    {
        int k = lists.size();
        ListNode *newlinkedlist = new ListNode(0), *newpointer = new ListNode(0);
        newlinkedlist->next = newpointer;
        priority_queue<pd, vector < pd>, myComp> p1;
        for (int i = 0; i < k; i++)
        {
            if (lists[i])
                p1.push({ lists[i]->val,
                    lists[i] });
        }
        while (!p1.empty())
        {
            auto gg = p1.top();
            p1.pop();
            newpointer->next = new ListNode(gg.first);
            newpointer = newpointer->next;
            if (gg.second->next)
            {
                auto ex = gg.second;
                ex = ex->next;
                p1.push({ ex->val,
                    ex });
            }
        }
        return newlinkedlist->next->next;

       	//         while(1){
       	//             ListNode* maxNode=new ListNode(INT_MAX);
       	//             bool got=false;
       	//             int i=0, maxNodepos=-1;
       	//             for(i=0; i < k; i++){
       	//                 if(lists[i] && maxNode->val > lists[i]->val){
       	//                     got=true;
       	//                     maxNode=lists[i];
       	//                     maxNodepos=i;
       	//                 }
       	//             }

       	//             if(got==false){
       	//                 break;
       	//             }else{
       	//                	// cout<<maxNode->val<<" ";
       	//                 if(newlinkedlist==nullptr){
       	//                     newlinkedlist=maxNode;
       	//                     newpointer=maxNode;
       	//                     maxNode=maxNode->next;
       	//                     lists[maxNodepos]=maxNode;
       	//                 }else{
       	//                     newpointer->next=maxNode;
       	//                     newpointer=newpointer->next;
       	//                     maxNode=maxNode->next;
       	//                     lists[maxNodepos]=maxNode;
       	//                 }
       	//             }

       	//         }

        return newlinkedlist;
    }
};