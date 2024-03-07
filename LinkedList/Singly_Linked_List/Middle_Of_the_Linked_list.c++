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
    int find(ListNode* head){
        if(head == NULL){
            return 0;
        }
        int count = 0;
        while(head != NULL){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        


        int len = find(head)/2;

        //ListNode* node = head;

        while(len>0){
            head = head->next;
            len--;
        }
        return head;
    }
};