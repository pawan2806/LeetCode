class Solution {
public:
    bool canJump(vector<int>& A) {
        int i = 0;
        int n=A.size();
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
    }
};