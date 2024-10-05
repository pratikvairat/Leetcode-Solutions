class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        int n = s1.size();
        int m = s2.size();
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);

        for (auto i : s1) {
            vec1[i - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            vec2[s2[i] - 'a']++;
        }

        int s = 0, e = n - 1;
        while (e < m) {
            if (vec1 == vec2) {
                return true;
            }
            
            vec2[s2[s] - 'a']--;  
            s++;
            e++;
            if (e < m) {
                vec2[s2[e] - 'a']++;  
            }
        }

        return false;
    }
};
