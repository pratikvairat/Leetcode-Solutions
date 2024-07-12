class Solution {
public:
    int pointsScored(string &s,string s1,int x){
        int points=0;
        stack<char> st;
        for(auto i: s){
            if(st.size()==0){
                st.push(i);
            }else{
                if(i==s1[1] && st.top()==s1[0]){
                    st.pop();
                    points+=x;
                }else{
                    st.push(i);
                }
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return points;
    }
    int maximumGain(string s, int x, int y) {
        string s1="ab",s2="ba";
        if(x<y){
            swap(s1,s2),swap(x,y);
        }
        return pointsScored(s,s1,x)+pointsScored(s,s2,y);
    }
};