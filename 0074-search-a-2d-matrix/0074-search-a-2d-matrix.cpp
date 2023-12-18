class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int a= matrix[0].size();
        int b=matrix.size();
        for(int i=0;i<b;i++){
            for(int j=0;j<a;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};