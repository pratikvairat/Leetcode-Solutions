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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int fcpi = -1;
        int prevcpi = -1;
        int curIndex = 1;
        ListNode* cur = head->next;
        ListNode* prev = head;
        vector<int> vec(1, 10000001);
        while (cur->next != NULL) {
            ListNode* nextNode = cur->next;
            if ((cur->val < nextNode->val && cur->val < prev->val) ||
                (cur->val > nextNode->val && cur->val > prev->val)) {
                if (prevcpi == -1) {
                    fcpi = curIndex;
                    prevcpi = curIndex;
                } else {
                    vec[0] = min(vec[0], curIndex - prevcpi);
                    prevcpi = curIndex;
                }
            }
            prev = prev->next;
            cur = cur->next;
            curIndex++;
        }
        if (fcpi != -1 && vec[0] != 10000001) {
            vec.push_back(prevcpi - fcpi);
        } else {
            vec[0] = -1;
            vec.push_back(-1);
        }
        return vec;
    }
};