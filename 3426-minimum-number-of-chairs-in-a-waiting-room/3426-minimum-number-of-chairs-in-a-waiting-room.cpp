class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'E') {
                cur++;
            } else {
                cur--;
            }
            ans = max(cur, ans);
        }
        return ans;
    }
};