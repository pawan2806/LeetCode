/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
   queue<int> list;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        listCreator(nestedList, list);
    }
void listCreator(vector<NestedInteger> &nestedList, queue<int> &list)
{
    for(auto i : nestedList)
    {
        if(i.isInteger())
            list.push(i.getInteger());
        else
            listCreator(i.getList(), list);
    }
}

int next() {
    int tmp = list.front();
    list.pop();
    return tmp;
}

bool hasNext() {
    return !list.empty();   
}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */