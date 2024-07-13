class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ids;
        int n=healths.size();
        for(int i=0;i<n;i++){
            ids.push_back(i);
        }
        auto compare=[&](int id1 ,int id2){
            return positions[id1]<=positions[id2];
        };

        sort(ids.begin(),ids.end(),compare);
        stack<int> st;
        for(auto id:ids){
            if(directions[id]=='R'){
                st.push(id);
            }else{
                while(!st.empty() && healths[id]>0){
                    if(healths[id]>healths[st.top()]){
                        healths[id]--;
                        healths[st.top()]=0;
                        st.pop();
                    }else if(healths[id]<healths[st.top()]){
                        healths[id]=0;
                        healths[st.top()]--;
                    }else{
                        healths[id]=0;
                        healths[st.top()]=0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for(auto i: healths){
            if(i>0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};