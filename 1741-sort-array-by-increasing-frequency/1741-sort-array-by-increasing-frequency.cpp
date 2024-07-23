class Solution {
public:
    static bool cmp(pair<int,int> &p,pair<int,int> &q){
        if(p.second!=q.second){
            return p.second<q.second;
        }
        return p.first>q.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        
        vector<pair<int,int>> vec;
        for(auto i: mp){
            vec.push_back({i.first,i.second});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int> ans;
        for(auto i: vec){
            for(int j=0;j<i.second;j++){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};