class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *slow = dummy, *fast = dummy;
        ListNode *preslow;
        
        while(fast && fast->next){
            preslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cout << preslow->val << ", " << slow->val << endl;
        
        //now slow is the midpoint(for odd-length list) or 
        // the node before midpoint(for even-length list)
        //preslow is the previous node of slow
        
        TreeNode* root = new TreeNode(slow->val);
        
        //cut the list's former part with the processed "slow"
        preslow->next = nullptr;
        //when slow==head, this node doesn't have left subtree
        root->left = (slow == head) ? nullptr : sortedListToBST(head);
        
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};