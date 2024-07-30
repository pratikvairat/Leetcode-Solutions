class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int b=0;
        int ans=0;
        for(auto i:s){
            if(i=='b'){
                b++;
            }else{
                if(b>0){
                    ans+=1;
                    b--;
                }else{
                    b=0;
                }
            }
        }
        return ans;
    }
};