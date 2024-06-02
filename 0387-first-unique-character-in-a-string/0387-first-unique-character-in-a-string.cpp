class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(27,0);
        int ans=-1;
        for(int i=0;i<s.size();i++){
            vec[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(vec[s[i]-'a']==1){
                ans=i;
                break;
            }
        }
        
        return ans;
    }
};