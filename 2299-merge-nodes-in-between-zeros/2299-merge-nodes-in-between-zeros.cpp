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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ans=nullptr,*temp=head,*res=nullptr;
        int sum=0;

        while(temp!=NULL){
            if(temp->val!=0){
                sum+=temp->val;
            }else{
                ListNode *temp2=new ListNode(sum);
                
                if(ans==NULL){
                    ans=temp2;
                }else{

                    ans->next=temp2;
                    if(res==nullptr){
                        res=ans;
                    }
                    ans=ans->next;
                }
                sum=0;
            }
            temp=temp->next;
        }
        return res->next;
    }
};