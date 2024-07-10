class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        for(auto i: logs){
            if(i=="../"){
                cnt--;
                if(cnt<0){
                    cnt=0;
                }
            }else if(i=="./"){
                
            }else{
                cnt++;
            }
        }
        if(cnt<0){
            return 0;
        }
        return cnt;
    }
};