class Solution {
public:
    vector<string> validStrings(int n) {
        if (n == 0) {
            return {};
        }
        vector<vector<string>> dp0(n + 1);
        vector<vector<string>> dp1(n + 1);
        dp0[1] = {"0"};
        dp1[1] = {"1"};
        for (int i = 2; i <= n; ++i) {
            for (auto s : dp1[i - 1]) {
                dp0[i].push_back(s + "0");
            }
            for (auto s : dp0[i - 1]) {
                dp1[i].push_back(s + "1");
            }
            for (auto s : dp1[i - 1]) {
                dp1[i].push_back(s + "1");
            }
        }
        vector<string> res;
        res.insert(res.end(), dp0[n].begin(), dp0[n].end());
        res.insert(res.end(), dp1[n].begin(), dp1[n].end());
        return res;
    }
};