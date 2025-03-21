class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indegree;

        unordered_set<string> supply(supplies.begin(),supplies.end());
        int n=recipes.size();
        for(int i=0;i<n;i++){
            indegree[recipes[i]]=0;
            for(auto &ingredient: ingredients[i]){
                if(supply.count(ingredient)==0){
                    adj[ingredient].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for(auto &[recipe,indeg]:indegree){
            if(indeg==0){
                q.push(recipe);
            }
        }
        vector<string> ans;
        while(!q.empty()){
            string rec=q.front();
            q.pop();
            ans.push_back(rec);
            for(auto next_rec: adj[rec]){
                indegree[next_rec]--;
                if(indegree[next_rec]==0){
                    q.push(next_rec);
                }
            }
        }
        return ans;
    }
};