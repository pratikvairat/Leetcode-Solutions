class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> mp; 
        int ans=0;
        for(auto j: arr1){
            string str=to_string(j);
            string prefix="";
            for(auto i: str){
                prefix+=i;
                mp.insert(prefix);
            }
        }
        for(auto i:arr2){
            string str=to_string(i);
            string prefix="";
            for(auto ch:str){
                prefix+=ch;
                if(mp.count(prefix)){
                    ans=max(ans,(int)prefix.size());
                }
            }
        }
        return ans;
    }
};