class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt++;
            }
        }
        

        if (cnt == 0 || cnt == n) {
            return 0;
        }

        int t = 0;
        for (int i = 0; i < cnt; i++) {
            if (nums[i] == 0) {
                t++;
            }
        }

        int mn = t;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == 0) {
                t--;
            }
            if (nums[(i + cnt - 1) % n] == 0) {
                t++;
            }
            mn = min(mn, t);
        }
        
        return mn;
    }
};
