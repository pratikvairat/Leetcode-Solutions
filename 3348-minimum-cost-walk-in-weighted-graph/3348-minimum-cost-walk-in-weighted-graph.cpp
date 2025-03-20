class Solution {
public:
    int find(vector<int>& dsu, int px) {
        if (dsu[px] == -1) {
            return px;
        }
        return dsu[px] = find(dsu, dsu[px]);
    }

    void traverseComponent(int& bitwise_and, int curr, vector<bool>& vis,
                           vector<vector<pair<int, int>>> &adj) {
                            vis[curr]=true;
                            for(auto &[i,j]:adj[curr]){
                                bitwise_and&=j;
                                if(!vis[i]){
                                    traverseComponent(bitwise_and,i,vis,adj);
                                }
                            }
                           }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        vector<int> dsu(n, -1);
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(make_pair(edge[1], edge[2]));
            adj[edge[1]].push_back(make_pair(edge[0], edge[2]));
            int px = find(dsu, edge[0]);
            int py = find(dsu, edge[1]);
            if (px != py) {
                dsu[px] = py;
            }
        }

        unordered_map<int, int> parent_cost;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int bitwise_and = adj[i].size() == 0 ? 0 : adj[i][0].second;
                traverseComponent(bitwise_and, i, vis, adj);
                int parent = find(dsu, i);
                parent_cost[parent] = bitwise_and;
            }
        }

        vector<int> ans;
        for (auto &q : query) {
            int px = find(dsu, q[0]);
            int py = find(dsu, q[1]);
            if (px == py) {
                ans.push_back(parent_cost[px]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};