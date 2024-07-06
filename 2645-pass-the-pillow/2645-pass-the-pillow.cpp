class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n){
            return time+1;
        }
        int roundDirection=time/(n-1);
        if(roundDirection%2!=0){
            return n-time%(n-1);
        }
        return time%(n-1)+1;
    }
};