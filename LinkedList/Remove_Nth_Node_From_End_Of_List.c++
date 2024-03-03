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
    int Count(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
       int count = Count(head);
       if(count == n){
        ListNode* newHead = head->next;
        delete head;
        return newHead;
       }
       ListNode* temp = head;
       int ram = 0;
       while(ram<count-n-1){
           temp = temp->next;
           ram++;
       }
       if (temp->next != nullptr) {
            ListNode* toRemove = temp->next;
            temp->next = toRemove->next;
            delete toRemove;
        }

        return head;
    }
};