class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,prefixSum=0;
        map<int,int> freq;
        freq[0]=1;
        for(auto i:nums){
            prefixSum+=i;
            if(freq[prefixSum-goal]!=0){
                ans+=freq[prefixSum-goal];
            }
            freq[prefixSum]++;
        }
        return ans;
    }
};