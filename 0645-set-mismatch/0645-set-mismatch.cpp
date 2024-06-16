class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> seen(n+1,0);
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            seen[nums[i]]++;
            if(seen[nums[i]]==2){
                ans.push_back(nums[i]);
            }
        }
        for(int i=1;i<=n;i++){
            if(seen[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};