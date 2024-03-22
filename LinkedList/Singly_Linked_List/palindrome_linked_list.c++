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
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* forward = NULL;
        while (current != NULL) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
            current = current->next;
        }
        return prev;
    }
    
public:
    void store(ListNode* head , stack<int> &s){
        if(head == NULL){
            return ;
        }
        while(head != NULL){
            s.push(head->val);
            head = head->next;
        }
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        stack<int> s;
        store(head,s);
        while(!s.empty()){
            int front = s.top();
            if(front == head->val){
                head = head->next;
                s.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};
