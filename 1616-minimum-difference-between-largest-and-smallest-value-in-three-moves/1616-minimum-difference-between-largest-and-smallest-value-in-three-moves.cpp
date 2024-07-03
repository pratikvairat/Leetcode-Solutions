class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4){
            return 0;
        }
        sort(nums.begin(),nums.end());
        priority_queue<int> mxHeap;
        priority_queue<int, vector<int>,greater<int>> mnHeap;

        for(auto i: nums){
            mxHeap.push(i);
            mnHeap.push(i);

            if(mxHeap.size()>4){
                mxHeap.pop();
            }
            if(mnHeap.size()>4){
                mnHeap.pop();
            }
        }
        int l=3, r=nums.size()-4;
        while(!mxHeap.empty()){
            nums[l--]=mxHeap.top();
            mxHeap.pop();
            nums[r++]==mnHeap.top();
            mnHeap.pop();
        }
        return min({nums[n-1]-nums[3],nums[n-2]-nums[2],nums[n-3]-nums[1],nums[n-4]-nums[0]});
        

    }
};