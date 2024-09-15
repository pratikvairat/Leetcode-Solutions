class Solution {
public:
    int findTheLongestSubstring(string s) {
        int xr = 0, ans = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                xr ^= c;
            }
            if (m.count(xr)) {
                ans = max(ans, i - m[xr]);
            } else {
                m[xr] = i;
            }
        }
        return ans;
    }
};