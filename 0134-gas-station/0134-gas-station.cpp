class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int s=0,t=0,curGas=0,ct=0;

        for(int i=0;i<n;i++){
            t+=gas[i];
            ct+=cost[i];
        }

        if(t<ct){
            return -1;
        }
        
        for(int i=0;i<n;i++){
            curGas=curGas+(gas[i]-cost[i]);
           
            if(curGas<0){
                s=i+1;
                curGas=0;
            }
        }

           
       
        return s;
        

        
    }
};