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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;

        int prefixsum = 0;

        ListNode* sampleone = new ListNode();
        sampleone->next = head;
        sampleone->val = 0;
        mp[0] = sampleone;

        while(head != NULL){
            prefixsum += head->val;

            if(mp.find(prefixsum) != mp.end()){
                ListNode* prevfound = mp[prefixsum];
                ListNode* temp = prevfound;
                int nosum = prefixsum;
                while(temp != head){
                    temp = temp->next;
                    nosum += temp->val;
                    if(temp != head)
                        mp.erase(nosum);
                }
                prevfound->next = temp->next;
            }
            else{
                mp[prefixsum] = head;
            }

            head = head->next;
        }
        return sampleone->next;
    }
};