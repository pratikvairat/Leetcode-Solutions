class Solution {
public:
    vector<string> convertToWordList(string s1){
        string s="";
        vector<string> vec;
        for(auto i: s1){
            if(i!=' '){
                s+=i;
            }else{
                vec.push_back(s);
                s="";
            }
        }
        if(s!=""){
            vec.push_back(s);
        }
        return vec;
    }
    bool areSentencesSimilar(string sen1, string sen2) {
        vector<string> vec1=convertToWordList(sen1);
        vector<string> vec2=convertToWordList(sen2);

        if(vec1.size()>vec2.size()){
            swap(vec1,vec2);
        }

        int l=0;

        while(l<vec1.size() && vec1[l]==vec2[l]){
            l++;
        }

        int r=vec1.size()-1;
        int w_pos=vec2.size()-1;
        while(r>=0 && vec1[r]==vec2[w_pos]){
            r--;
            w_pos--;
        }

        return l>r;
    }
};