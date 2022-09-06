/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        typedef pair<int, ListNode*> pd;
    struct myComp
    {
        bool operator()(pair<int, ListNode*>
            const &a, pair<int, ListNode*>
            const &b)
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
    }
};