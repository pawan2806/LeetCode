class Solution {
public:
   bool dfs(string cur, string target, unordered_map<string, vector<pair<string, double>>>& adjlist, unordered_set<string>& visited, double& val) {
        if (!adjlist.count(target) or !adjlist.count(cur)) {
            // not in graph
            return false;
        }
        else if (cur == target) {
            // found, val is the result
            return true;
        }
        else {
            // keep searching
            visited.insert(cur);
            for (auto& node : adjlist[cur]) {
                if (!visited.count(node.first)) {
                   
                    val *= node.second;
                    if (dfs(node.first, target, adjlist, visited, val)) {
                        return true;
                    }
                    val/= node.second;
                }
            }
			// no path found
            return false;
        }
    }
        
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // construct graph adj list
        unordered_map<string, vector<pair<string, double>>> adjlist;
        for (int i(0); i < equations.size(); ++i) {
            string nume = equations[i][0];
            string deno = equations[i][1];
            double rst = values[i];
            
          
            adjlist[nume].push_back(make_pair(deno, rst));
           
            adjlist[deno].push_back(make_pair(nume, 1.0 / rst));
        }
        // process each query by DFS
        vector<double> rst;
        for (const auto& x : queries) {
            unordered_set<string> visited;
            double val = 1.0;
            if (dfs(x[0], x[1], adjlist, visited, val)) {
                rst.push_back(val);
            }
            else {
                rst.push_back(-1.0);
            }
        }
        return rst;
    }
};