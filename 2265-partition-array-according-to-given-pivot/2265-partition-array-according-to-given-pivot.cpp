class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lvec;
        vector<int> gvec;
        int pnum=0;
        int n=nums.size();
        for(auto i:nums){
            if(i<pivot){
                lvec.push_back(i);
            }
            if(i>pivot){
                gvec.push_back(i);
            }
            if(pivot==i){
                pnum++;
            }
        }
        int j=0;
        for(auto i: lvec){
            nums[j]=i;
            j++;
        }
        for(int i=0;i<pnum;i++){
            nums[j]=pivot;
            j++;
        }
        for(auto i:gvec){
            nums[j]=i;
            j++;
        }
        return nums;

    }
};