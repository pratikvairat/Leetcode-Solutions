class Solution {
public:
    int minSwaps(string st) {
        int s = 0;
        int n = st.size();
        for (auto i : st) {
            if (i == '[') {
                s++;
            } else if (s > 0) {
                s--;
            }
        }
        return (s + 1) / 2;
    }
};