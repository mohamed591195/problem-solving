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
// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         stack<int> s;
//         ListNode* fast = head, * slow = head;
//         while (fast && fast->next){
//             fast = fast->next->next;
//             s.push(slow->val);
//             slow = slow->next;
//         }

//         int maxTwin = 0;
//         while(slow){
//             maxTwin = max(maxTwin, s.top() + slow->val);
//             s.pop();
//             slow = slow->next;
//         }
//         return maxTwin;
//     }
// };

// another solution that utilize linked-list reverse algorithm
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* fast = head, * slow = head;
        // getting the middle node at slow
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* next = nullptr, *prev = nullptr;
        while(slow) {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        int maxTwin = 0;
        // now we are at head of the second half not the tail
        slow = prev;
        while(slow){
            maxTwin = max(maxTwin, head->val + slow->val);
            head = head->next;
            slow = slow->next;
        }
        return maxTwin;
    }
};