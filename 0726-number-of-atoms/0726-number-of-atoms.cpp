class Solution {
public:
    
    string countOfAtoms(string formula) {
        int j,k;
        stack<pair<string,int>> st;
        int n=formula.size();
        for(int i=0;i<n;i++){
            char ch=formula[i];
            if(isupper(ch)){
                string ele="";
                ele+=ch;
                for(j=i+1;j<n;j++){
                    ch=formula[j];
                    if(!islower(ch)){
                        break;
                    }
                    ele+=ch;
                }

                string d="";
                for(k=j;k<n;k++){
                    ch=formula[k];
                    if(!isdigit(ch)){
                        break;
                    }
                    d+=ch;
                }
                if(d==""){
                    d="1";
                }
                int digit=stoi(d);
                st.push({ele,digit});
                i=k-1;
            }else if(ch=='('){
                st.push({"(",-1});
            }else if(ch==')'){
                string d="";
                for(j=i+1;j<n;j++){
                    ch=formula[j];
                    if(!isdigit(ch)){
                        break;
                    }
                    d+=ch;
                }
                if(d==""){
                    d="1";
                }
                int digit=stoi(d);
                vector<pair<string,int>> temp;
                pair<string,int> openingPair={"(",-1};
                while(st.top()!=openingPair){
                    pair<string,int> p=st.top();
                    st.pop();
                    temp.push_back({p.first,p.second*digit});
                }
                st.pop();
                while(temp.size()>0){
                    st.push(temp.back());
                    temp.pop_back();
                }
                i=j-1;
            }

        }
        map<string,int> mp;
        while(!st.empty()){
            pair<string,int> p=st.top();
            st.pop();
            mp[p.first]+=p.second;
        }
        string ans="";
        for(auto p:mp){
            string str=p.first;
            string d=to_string(p.second);
            if(d=="1"){
                d="";
            }
            ans+=str+d;
        }
        
        return ans;
    }
};