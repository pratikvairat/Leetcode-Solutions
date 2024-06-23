class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> mp(10000+1,0);
        for (auto i : nums) {
            mp[i]++;
        }
        while (mp[original]) {
            original = 2 * original;
        }
        return original;
    }
};