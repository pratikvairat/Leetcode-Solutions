class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(auto i:nums){
            if(i%3){
                cnt++;
            }
        }
        return cnt;
    }
};