class Solution {
private:
    // Find the group of an element
    int f(vector<int>& p, int e) {
        if(p[e] == e) return e;
         else { 
            p[e] = f(p, p[e]);
            return p[e];
        }
    }

    // Union two groups
    void u(vector<int>& p, int e1, int e2) {
        int r1 = f(p, e1);
        int r2 = f(p, e2);

        if(r1 == r2) return;

        p[r2] = r1;
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> p(n);
        
        for(int i = 0; i < n; i ++) p[i] = i; // Initialize parent array for union find
        
        for(vector<int>& x : pairs) u(p, x[0], x[1]); // Union all pairs
        
        vector<vector<char>> g(n);

        for(int i = 0; i < n; i ++) {
            g[f(p, i)].push_back(s[i]); // Seperate characters by group
        }
        
        for(int i = 0; i < n; i ++) sort(g[i].begin(), g[i].end()); // Sort each group
        
        vector<int> in(n);
        vector<char> ans;
        
        for(int i = 0; i < n; i ++) {
            int c = f(p, i);
            ans.push_back(g[c][in[c] ++]); // Add each group back into answer
        }
        
        return string(ans.begin(), ans.end());
    }
};