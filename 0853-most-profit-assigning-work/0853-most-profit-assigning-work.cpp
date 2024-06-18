class Solution {
public:
    int BinarySearch(vector<pair<int, int>> vec, int m) {
        int lo = 0;
        int hi = vec.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (vec[mid].first <= m) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return hi;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> vec;
        int n = profit.size();
        for (int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }
        sort(vec.begin(), vec.end());
        int m = worker.size();
        vector<pair<int, int>> maxProfitDiffuculty;
        int mx = 0;
        for (auto i : vec) {
            mx = max(mx, i.second);
            maxProfitDiffuculty.push_back({i.first, mx});
        }
        int ans = 0;
        for (auto i : worker) {
            int k = BinarySearch(maxProfitDiffuculty, i);
            if (k >= 0 && i >= maxProfitDiffuculty[k].first) {
                ans += maxProfitDiffuculty[k].second;
            }
        }
        return ans;
    }
};