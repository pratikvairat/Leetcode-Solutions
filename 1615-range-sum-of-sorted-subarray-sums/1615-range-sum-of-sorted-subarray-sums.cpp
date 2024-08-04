class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vec;
        
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                vec.push_back(s);
            }
        }
        sort(vec.begin(),vec.end());
        int ans=0;
        int MOD=1e9+7;
        for(int i=left-1;i<right;i++){
            ans=(ans+vec[i])%MOD;
        }
        return ans;
    }
};