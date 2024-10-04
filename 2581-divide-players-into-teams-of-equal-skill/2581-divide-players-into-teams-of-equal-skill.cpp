class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int gn=n/2;
        int s=0;
        sort(skill.begin(),skill.end());
        for(auto i: skill){
            s+=i;
        }
        if(s%gn!=0){
            return -1;
        }
        long long ans=0;
        for(int i=0;i<gn;i++){
            if(skill[i]+skill[n-1-i]!=s/gn){
                return -1;
            }
            ans+=(skill[i]*skill[n-1-i]);
        }
        return ans;
    }
};