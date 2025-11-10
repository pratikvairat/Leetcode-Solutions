class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer> mp=new HashMap<>();
        int res=0;
        int majority=0;

        for(int i=0;i<nums.length;i++){
            mp.put(nums[i],1+mp.getOrDefault(nums[i],0));
            if(mp.get(nums[i])>majority){
                res=nums[i];
                majority=mp.get(nums[i]);
            }
        }

        return res;

       
    }
}