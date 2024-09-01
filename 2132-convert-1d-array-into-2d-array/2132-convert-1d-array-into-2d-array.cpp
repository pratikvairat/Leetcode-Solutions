class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s=original.size();
        if(s!=(m*n)){
            return {};
        }
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[k];
                k++;
            }
        }
        return ans;
    }
};