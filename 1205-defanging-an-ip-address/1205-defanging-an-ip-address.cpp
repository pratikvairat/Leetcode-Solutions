class Solution {
public:
    string defangIPaddr(string address) {
        string str="";
        for(auto i:address){
            if(i=='.'){
                str=str+"[.]";
            }else{
                str=str+i;
            }
            
        }
        return str;
    }
};