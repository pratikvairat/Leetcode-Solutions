class Node{
    public:
    int cnt;
    Node* child[26];
    Node(){
        cnt=0;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* node=root;
        for(auto i: s){
            int n=i-'a';
            if(!node->child[n]){
                node->child[n]=new Node();
            }
            node=node->child[n];
            node->cnt++;
        }
    }

    vector<int> solve(vector<string> & words){
        vector<int> ans;
        
        for(auto word:words){
            int cn=0;
            Node* node=root;
            for(auto ch:word){
                int i=ch-'a';
                if(!node->child[i]){
                    break;
                }
                node=node->child[i];
                cn+=node->cnt;
            }
            ans.push_back(cn);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        for(auto i: words){
            t.insert(i);
        }
        return t.solve(words);
    }
};