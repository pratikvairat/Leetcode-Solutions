class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rem(k,0);
        for(auto i:arr){
            int r=i%k;
            if(r<0){
                r+=k;
            }
            rem[r]++;
        }
        if(rem[0]%2!=0){
            return false;
        }
        for(int i=1;i<=k/2;i++){
            if(rem[i]!=rem[k-i]){
                return false;
            }
        }
        return true;
    }
};