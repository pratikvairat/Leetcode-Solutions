class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vec;
        int n=timePoints.size();
        for (auto time : timePoints) {
            int val = (((time[0] - '0') * 10 + (time[1] - '0')) * 60) +
                      ((time[3] - '0') * 10 + (time[4] - '0'));
            cout << time[0] - '0' << " " << time[1] - '0' << " ";
            vec.push_back(val);
        }
        sort(vec.begin(), vec.end());
        int mn=INT_MAX;
        for(int i=1;i<n;i++){
            mn=min(vec[i]-vec[i-1],mn);
        }
        return min(mn,1440-vec[n-1]+vec[0]);
    }
};