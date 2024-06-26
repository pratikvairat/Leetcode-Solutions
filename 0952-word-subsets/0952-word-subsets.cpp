
class Solution {
public:
    unordered_map<char, int> mp1;
    bool isSubset(string str) {
        unordered_map<char, int> count;
        for (auto ch : str) {
            count[ch]++;
        }
        for (auto& pair : mp1) {
            if (count[pair.first] < pair.second) {
                return false;
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;

        for (auto& word : words2) {
            unordered_map<char, int> count;
            for (auto ch : word) {
                count[ch]++;
            }
            for (auto& pair : count) {
                mp1[pair.first] = max(mp1[pair.first], pair.second);
            }
        }
        for (auto& word : words1) {
            if (isSubset(word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
