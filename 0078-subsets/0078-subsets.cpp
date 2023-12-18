class Solution {
public:
    void solve(vector<int> nums,int i,vector<int> output,vector<vector<int>> &ans){
        if(i>=nums.size()){
            ans.push_back(output);
            return ;
        }
        //exclude call 
        solve(nums,i+1,output,ans);
        //include call
        output.push_back(nums[i]);
        solve(nums,i+1,output,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int i=0;
        solve(nums,i,output,ans);
        return ans;
    }
};