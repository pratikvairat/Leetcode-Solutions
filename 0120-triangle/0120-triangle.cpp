class Solution {
public:
    unordered_map<string, int> memo;

    int solve(vector<vector<int>> &triangle, int x, int y, int size) {
        if (x == size - 1) {
            return triangle[x][y];
        }

        string key = to_string(x) + "," + to_string(y);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int rpick = solve(triangle, x + 1, y + 1, size) + triangle[x][y];
        int lpick = solve(triangle, x + 1, y, size) + triangle[x][y];

        memo[key] = min(rpick, lpick);
        return memo[key];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int size=triangle.size();
        if(size==1){
            return triangle[0][0];
        }
        
        return solve(triangle,0,0,size);
    }
};