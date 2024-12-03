class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str = "";
        int n = s.size();
        int j = 0, m = spaces.size();

        for (int i = 0; i < n; i++) {
            if (j < m && i == spaces[j]) { // Correct condition
                str += " ";
                j++;
            }
            str += s[i];
        }

        return str;
    
    }
};