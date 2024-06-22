class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0,prefixSum=0;
        int n=nums.size();
        unordered_map<int,int> freq;
        freq[0]=1;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else{
                nums[i]=1;
            }
        }
        

        for(auto i:nums){
            prefixSum+=i;
            if(freq[prefixSum-k]!=0){
                ans+=freq[prefixSum-k];
            }
            freq[prefixSum]++;
        }
        return ans;
    }
};