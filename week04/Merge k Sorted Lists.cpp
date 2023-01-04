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
class Solution
{
public:
    ///Time Complexity O(KM); M = Total number of elements, K= total number of lists
    ListNode* mergeTwoLists (ListNode* left, ListNode* right)
    {
        ListNode* dummyHead = new ListNode(0);
        ListNode* copyHead = dummyHead;

        while(left and right)
        {
            int vleft = left->val;
            int vright = right->val;
            if(vleft<vright)
            {
                dummyHead->next = new ListNode(vleft);
                left = left->next;
            }
            else
            {
                dummyHead->next = new ListNode(vright);
                right = right->next;
            }
            dummyHead = dummyHead->next;
        }
        while(right)
        {
            dummyHead->next = new ListNode(right->val);
            dummyHead = dummyHead->next;
            right = right->next;
        }
        while(left)
        {
            dummyHead->next = new ListNode(left->val);
            dummyHead = dummyHead->next;
            left = left->next;
        }
        return copyHead->next;
    }

    ListNode* helper (int L, int R, vector<ListNode*>& lists)
    {
        if(L>R)
            return NULL;
        if(L==R)
            return lists[L];
        int M = (L+R)/2;
        auto left = helper(L, M, lists);
        auto right = helper(M+1, R, lists);
        return mergeTwoLists(left, right);

    }
    ListNode* mergeKLists (vector<ListNode*>& lists)
    {
        return helper(0, lists.size()-1, lists);
    }
};
