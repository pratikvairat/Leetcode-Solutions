class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(auto i:arr2){
            for(int j=0;j<mp[i];j++){
                ans.push_back(i);
            }
            mp.erase(i);
        }
        for(auto i:mp){
            for(int j=0;j<i.second;j++){
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};