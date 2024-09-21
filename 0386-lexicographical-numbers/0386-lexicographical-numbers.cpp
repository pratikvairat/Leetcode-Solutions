class Solution {
public:
    vector<int> lexicalOrder(int n) {
        priority_queue<string,vector<string>, greater<string>> heap;

        for(int i=1;i<=n;i++){
            heap.push(to_string(i));
        }

        vector<int> ans;
        while(!heap.empty()){
            ans.push_back(stoi(heap.top()));
            heap.pop();
        }

        return ans;
    }
};