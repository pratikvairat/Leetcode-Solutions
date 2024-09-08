/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int n=0;
        ListNode* curr=head;
        while(curr!=NULL){
            n++;
            curr=curr->next;
        } 
        int s=n/k;
        int r=n%k;
        curr=head;
        ListNode *prev=curr;
        for(int i=0;i<k;i++){
            ListNode* newPart=curr;
            int currSize=s;
            if(r>0){
                r--;
                currSize++;
            }
            int j=0;
            while(j<currSize){
                prev=curr;
                if(curr!=NULL){
                    curr=curr->next;
                }
                j++;
            }
            if(prev!=NULL){
                prev->next=NULL;
            }
            ans[i]=newPart;
        }
        return ans;
    }
};