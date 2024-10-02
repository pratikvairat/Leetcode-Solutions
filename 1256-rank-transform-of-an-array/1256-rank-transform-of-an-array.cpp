class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s;
        for(auto i: arr){
            s.insert(i);
        }
        map<int,int> mp;
        int n=1;
        for(auto i:s){
            mp[i]=n;
            n++;
        }
        vector<int> vec;
        for(auto i: arr){
            vec.push_back(mp[i]);
        }
        return vec;
    }
};