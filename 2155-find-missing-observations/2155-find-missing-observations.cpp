class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int k=n+m;
        int rsum=mean*k;
        int sum=0;
        for(auto i:rolls){
            sum+=i;
        }
        int rq=rsum-sum;
        int x=rq/n,y=rq%n;
        if(x<=0 ||x>6){
            return {};
        }
        if(x==6 && y>0){
            return {};
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=x;
        }
        for(int i=0;i<y;i++){
            ans[i]++;
        }
        return ans;
    }
};