class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> mn(m,INT_MAX);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mn[i]=min(mn[i],matrix[i][j]);
            }
        }
        vector<int> mx(n,INT_MIN);
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                mx[j]=max(mx[j],matrix[i][j]);
            }
        }
        vector<int> vec;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mn[i]==matrix[i][j] && mx[j]==matrix[i][j]){
                    vec.push_back(matrix[i][j]);
                }
            }
        }
        
        return vec;
    }
};