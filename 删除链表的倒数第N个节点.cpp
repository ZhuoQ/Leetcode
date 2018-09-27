/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* node = head;
        ListNode* del = nullptr;
        while(node!=nullptr){
            nodes.push_back(node);
            node = node -> next;
        }
        
        if(n!=1){
            if(nodes.size()==n){
                ListNode* next = nodes[nodes.size()-n+1];
                head = head -> next;
            } else {
                ListNode* pre = nodes[nodes.size()-n-1];
                ListNode* next = nodes[nodes.size()-n+1];
                // ListNode = ListNode
                pre -> next = pre -> next -> next;
            }
            
            
            // del =  
        } else {
            ListNode* pre = nodes[nodes.size()-n-1];
            if(nodes.size()==1){
                head = nullptr;
                // return nullptr;
            } else {
                pre -> next = nullptr;
            }
        }
        return head;
    }
};