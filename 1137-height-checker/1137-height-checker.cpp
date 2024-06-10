class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> high=heights;
        sort(high.begin(),high.end());
        int n=0;
        for(int i=0;i<heights.size();i++){
            if(high[i]!=heights[i]){
                n++;
            }
            
        }
        return n;
    }
};