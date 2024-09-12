class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> vec(27,false);
        for(auto i: allowed){
            vec[i-'a']=true;
        }
        int cnt=0;
        for(auto st:words){
            bool f=true;
            for(auto i: st){
                if(vec[i-'a']==false){
                    f=false;
                    break;
                }
            }
            if(f){
                cnt++;
            }
        }
        return cnt;
    }
};