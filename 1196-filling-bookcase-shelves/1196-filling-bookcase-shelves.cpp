class Solution {
public:
    int solve(int i,vector<vector<int>> &books, int width,vector<int> &dp){
        if(i>=books.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int w=0,hmx=0;
        int ans=INT_MAX;
        for(int j=i;j<books.size();j++){
            w+=books[j][0];
            if(w>width){
                break;
            }
            hmx=max(hmx,books[j][1]);
            ans=min(hmx+solve(j+1,books,width,dp),ans);
        }
        dp[i]=ans;
        return ans;


    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size(),-1);
        int ans=solve(0,books,shelfWidth,dp);
        return ans;
    }
};