class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int j=-1;
        int mx=*max_element(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i]!=mx){
                j=i;
            }
            res=max(res,i-j);
        }
        return res;
    }
};