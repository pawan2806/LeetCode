class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> edge;
        unordered_map<string, int> indegree;
        unordered_set<string> available(supplies.begin(), supplies.end());
        for (int i=0; i<recipes.size(); ++i) {
            for (int j=0; j < ingredients[i].size(); ++j) {
                edge[ingredients[i][j]].push_back(recipes[i]);
                if (!indegree.count(ingredients[i][j])) {
                    indegree[ingredients[i][j]] = 0;
					
                }
            }
            indegree[recipes[i]] = ingredients[i].size();
        }
        queue<string> myQueue; 
        for (auto it=indegree.begin(); it != indegree.end(); ++it) {
            if (it->second == 0 && available.count(it->first)) {
                myQueue.push(it->first);
            }
        }
        while (!myQueue.empty()) {
            string front = myQueue.front();
            myQueue.pop();
            for (int i=0; i<edge[front].size(); ++i) {
                indegree[edge[front][i]] --;
                if (indegree[edge[front][i]] == 0) {
                    myQueue.push(edge[front][i]);
                    available.insert(edge[front][i]);
                }
            }
        }
        vector<string> ans;
        for (int i=0; i<recipes.size(); ++i) {
            if (available.count(recipes[i])) {
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};