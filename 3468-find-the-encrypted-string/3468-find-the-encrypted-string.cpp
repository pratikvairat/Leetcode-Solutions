class Solution {
public:
    string getEncryptedString(string s, int k) {
        string cp=s;
        int n=s.size();
        for(int i=0;i<n;i++){
            cp[i]=s[(i+k)%n];
        }
        return cp;
    }
};