class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        map<string, int> words;
        string word = "";
        for (auto i : s) {
            if (i == ' ') {
                words[word]++;
                word = "";
            } else {
                word += i;
            }
        }
        if (word != "") {
            words[word]++;
            word = "";
        }
        vector<string> ans;
        for (auto i : words) {
            if (i.second == 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};