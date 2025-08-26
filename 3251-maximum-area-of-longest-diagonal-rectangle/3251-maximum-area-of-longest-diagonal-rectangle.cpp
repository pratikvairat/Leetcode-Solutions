class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        double dia=0;

        for(auto i: dimensions){
            double curDia=sqrt(i[0]*i[0]+i[1]*i[1]);
            if(dia<curDia){
                ans=i[0]*i[1];
                dia=curDia;
            }else if(dia==curDia){
                ans=max(ans,i[0]*i[1]);
                dia=curDia;
            }
        }
        return ans;
    }
};