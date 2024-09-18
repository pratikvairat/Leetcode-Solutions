class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(auto i:nums){
            vec.push_back(to_string(i));
        }

        sort(vec.begin(),vec.end(),[](string &a,string &b){
            return (b+a)<(a+b);
        });

        if(vec[0]=="0"){
            return "0";
        }

        string ans="";
        for(auto i: vec){
            ans+=i;
        }
        return ans;
    }
};