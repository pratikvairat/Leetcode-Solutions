class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mp1,mp2;
        if(target.size()!=arr.size()){
            return false;
        }
        for(auto i: target){
            mp1[i]++;
        }
        for(auto i: arr){
            mp2[i]++;
        }
        for(auto i: arr){
            if(mp1[i]!=mp2[i]){
                return false;
            }
        }
        return true;
    }
};