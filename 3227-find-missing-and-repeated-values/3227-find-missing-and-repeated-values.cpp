class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int a,b;
        vector<int> vis((n*n)+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[grid[i][j]]==1){
                    a=grid[i][j];
                }
                vis[grid[i][j]]++;
            }
        }
        for(int i=1;i<(n*n)+1;i++){
            if(vis[i]==0){
                b=i;
                break;
            }
        }

        return {a,b};

    }
};