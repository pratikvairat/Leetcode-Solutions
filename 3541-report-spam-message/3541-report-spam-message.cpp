class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string,bool> mp;
        for(auto i:bannedWords){
            mp[i]=true;
        }
        int cnt=0;
        for(auto i: message){
            if(mp[i]){
                cnt++;
            }
            if(cnt==2){
                return true;
            }
        }
        return false;
    }
};