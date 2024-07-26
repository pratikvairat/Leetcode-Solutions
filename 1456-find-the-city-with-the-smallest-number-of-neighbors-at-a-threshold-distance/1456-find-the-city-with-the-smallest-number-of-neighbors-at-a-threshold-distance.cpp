class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 100001));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int node = 0; node < n; node++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    if (dist[u][v] > dist[u][node] + dist[node][v]) {
                        dist[u][v] = dist[u][node] + dist[node][v];
                    }
                }
            }
        }
        int mn = 100001;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= mn) {
                ans = i;
                mn = cnt;
            }
        }
        return ans;
    }
};