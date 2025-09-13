class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        for(auto i:s){
            freq[i-'a']++;
        }
        int mx1=0,mx2=0;

        for(int i=0;i<26;i++){
            if(i!=0 && i!=4 && i!=8 && i!=14 && i!=20){
                mx1=max(freq[i],mx1);
            }else{
                mx2=max(mx2,freq[i]);
            }
        }
       
        return mx1+mx2;
    }
};