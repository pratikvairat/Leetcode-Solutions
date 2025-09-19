class Solution {
public:
    string toString(string s){
        int n=s.size();
        string st="";
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                st+=tolower(s[i]);
            }
        }
        return st;
    }
    bool isPalindrome(string s) {
        string st=toString(s);
        int n=st.size()-1;
        int i=0;
        while(i<=n){
            if(st[i]!=st[n]){
                return false;
            }
            i++;
            n--;
        }
        return true;
    }
};