class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;
        for (auto c : word) {
            mp[c]++;
        }
        
        vector<pair<int, char>> freqVector;
        for (auto it : mp) {
            freqVector.push_back({it.second, it.first});
        }
        sort(freqVector.rbegin(), freqVector.rend());
        
        map<char, int> mp1;
        int cnt = 0;
        for (auto it = freqVector.begin(); it != freqVector.end(); ++it) {
            mp1[it->second] = (cnt / 8) + 1;
            cnt++;
        }
        
        int ans = 0;
        for (auto c : word) {
            ans += mp1[c];
        }
        
        return ans;
    }
};