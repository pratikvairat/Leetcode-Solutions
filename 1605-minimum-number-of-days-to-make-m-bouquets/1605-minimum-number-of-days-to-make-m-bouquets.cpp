class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int k, int m, int d) {
        int cnt = 0;
        int numOfB = 0;
        for (auto i : bloomDay) {
            if (i <= d) {
                cnt++;
            } else {
                numOfB += (cnt / k);
                cnt = 0;
            }
        }
        numOfB += (cnt / k);
        return numOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int mn = *min_element(bloomDay.begin(), bloomDay.end());
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if (val > n) {
            return -1;
        }
        
        int lo = mn, hi = mx;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (isPossible(bloomDay, k, m, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};