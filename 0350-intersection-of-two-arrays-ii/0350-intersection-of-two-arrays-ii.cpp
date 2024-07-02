class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1;
        map<int,int> mp2;
        vector<int> vec;
        int n=nums1.size();
        int m=nums2.size();
        for(auto i:nums1){
            mp1[i]++;
        }
        for(auto i:nums2){
            mp2[i]++;
        }
        if(n>=m){
            for(auto i:nums1){
                if(mp1[i]<=mp2[i] && i!=-1){
                    for(int j=0;j<mp1[i];j++){
                        vec.push_back(i);
                    }
                    mp1[i]=0;
                    mp2[i]=0;
                }else{
                    for(int j=0;j<mp2[i];j++){
                        vec.push_back(i);
                    }
                    mp1[i]=0;
                    mp2[i]=0;
                }
            }
        }else{
             for(auto i:nums2){
                if(mp1[i]<=mp2[i] && i!=-1){
                    for(int j=0;j<mp1[i];j++){
                        vec.push_back(i);
                    }
                    mp1[i]=0;
                    mp2[i]=0;
                }else{
                    for(int j=0;j<mp2[i];j++){
                        vec.push_back(i);
                    }
                    mp1[i]=0;
                    mp2[i]=0;
                }
            }
        }
        return vec;
    }
};