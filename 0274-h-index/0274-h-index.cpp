class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (citations[i] >= n - i) {
                ans = n - i;
            } else {
                break;
            }
        }
        return ans;
    }
};