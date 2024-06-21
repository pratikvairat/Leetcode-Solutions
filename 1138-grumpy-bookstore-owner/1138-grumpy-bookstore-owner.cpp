class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int cur=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                cur+=customers[i];
            }
        }
        sort(customers.begin(),customers.begin());
        int mx=cur;
        vector<int> vec(n+1,0);
        for(int i=0;i<=n-minutes;i++){
            for(int j=0;j<minutes;j++){
                if(grumpy[i+j]==1){
                    mx+=customers[i+j];
                }
            }
            vec[i]=max(mx,cur);
            mx=cur;
        }
        return *max_element(vec.begin(),vec.end());

    }
};