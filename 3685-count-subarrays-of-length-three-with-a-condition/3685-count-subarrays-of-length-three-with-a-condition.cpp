class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            if((float)nums[i]+(float)nums[i+2]==(float)nums[i+1]/2){
                ans++;
            }
        }
        return ans;
    }
};