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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> vec(m, vector<int>(n, -1));
        int i = 0, j = 0, p = 0;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        ListNode* temp = head;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        while (temp != NULL) {
            vec[i][j] = temp->val;
            temp = temp->next;
            int ni = i + dir[d][0], nj = j + dir[d][1];
            if (ni > bottom || nj < top || nj > right || ni < left ||
                vec[ni][nj] != -1) {
                
                d = (d + 1) % 4;
                ni = i + dir[d][0];
                nj = j + dir[d][1];
            }
            i = ni;
            j = nj;
        }
        return vec;
    }
};