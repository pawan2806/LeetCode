class Solution
{
    public:
        void dfs(int v, int p, vector<vector < int>> &g, vector< int > &vis, vector< vector< int >> &ve, int k, vector< int > &low, vector< int > &tin)
        {

            int n = k;
            vis[v] = 1;
            tin[v] = low[v] = n++;

            for (auto child: g[v])
            {
                if (p == child) continue;
                if (!vis[child])
                {

                    dfs(child, v, g, vis, ve, n, low, tin);

                    low[v] = min(low[v], low[child]);

                    if (low[child] > tin[v])
                        ve.push_back({ child,
                            v });
                }
                low[v] = min(low[v], tin[child]);
            }
        }

    vector<vector < int>> criticalConnections(int n, vector<vector < int>> &c)
    {

        vector<vector < int>> g(n);
        vector<vector < int>> ve;

        for (auto it: c)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> tin(n, -1);
        vector<int> low(n, -1);

        vector<int> vis(n, 0);

        dfs(0, -1, g, vis, ve, 0, tin, low);

        return ve;
    }
};