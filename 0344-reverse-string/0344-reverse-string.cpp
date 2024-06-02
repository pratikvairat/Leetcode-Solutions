class Solution {
public:
    void reverseString(vector<char>& a) {
        int s=0;
        int t=a.size()-1;
        while(s<t){
            swap(a[s],a[t]);
            t--;
            s++;
        }
    }
};