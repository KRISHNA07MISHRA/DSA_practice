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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int n = 0;
        ListNode* radha = list2;
        while(radha ->next != NULL){
            radha  = radha->next;
        }
        ListNode* temp = list1;
        ListNode* hemp = list1;
        while(n<a-1){
            temp = temp->next;
            n++;
            
        }
        n = 0;
        while(n<=b){
            hemp = hemp->next;
            n++;
        }
        temp->next = list2;
        radha ->next = hemp;
        return list1;
    }
};