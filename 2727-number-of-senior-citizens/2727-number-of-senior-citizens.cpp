class Solution {
public:
    bool check(string &s){
        if(s[11]=='6' && s[12]!='0'){
            return true;
        }
        if(s[11]=='7' || s[11]=='8' || s[11]=='9'){
            return true;
        }
        return false;
    }
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto i: details){
            if(check(i)){
                cnt++;
            }
        }
        return cnt;
    }
};