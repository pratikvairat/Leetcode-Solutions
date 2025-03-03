// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int last=n;
        int first=1;
        
        while(first<last){
            int mid=first+(last-first)/2;
            if(isBadVersion(mid)){
                last=mid;
            }else{
                first=mid+1;
            }
            
        }
        return first;
    }
};