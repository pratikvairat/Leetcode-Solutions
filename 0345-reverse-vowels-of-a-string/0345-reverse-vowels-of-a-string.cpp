class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (!isVowel(s[i])) {
                i++;
            }
            if (!isVowel(s[j])) {
                j--;
            }
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
    bool isVowel(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            return true;
        }
        if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') {
            return true;
        }
        return false;
    }
};