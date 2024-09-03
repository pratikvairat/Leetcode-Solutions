class Solution {
public:
    int getLucky(string s, int k) {
        string num="";
        for(auto i:s){
            num+=to_string(i-'a'+1);
        }
        while(k>0){
            int temp=0;
            for(char x:num){
                temp+=x-'0';
            }
            num=to_string(temp);
            k--;
        }
        return stoi(num);
    }
};