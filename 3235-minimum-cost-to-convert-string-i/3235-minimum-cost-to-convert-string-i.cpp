class Solution {
public:
    int INM=100000001;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26,vector(26,INM));
        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            int from=original[i]-'a';
            int to=changed[i]-'a';
            dist[from][to]=min(dist[from][to],cost[i]);
        }
        for(int node=0;node<26;node++){
            for(int u=0;u<26;u++){
                for(int v=0;v<26;v++){
                    if(u==v){
                        continue;
                    }
                    dist[u][v]=min(dist[u][node]+dist[node][v],dist[u][v]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]){
                continue;
            }
            if(dist[source[i]-'a'][target[i]-'a']>=INM){
                return -1;
            }
            ans+=dist[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};