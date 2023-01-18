///Time Complexity O(n) n is the number of nodes;
///Space Complexity O(1)

#include<bits/stdc++.h>
using namespace std;


class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void makeCycle (ListNode* head, int pos)
    {
        ListNode* temp = head;
        ListNode* startNode;
        int count =1;
        while(temp->next!=NULL)
        {
            if(count==pos)
            {
                startNode = temp;
            }
            temp = temp->next;
            count++;
        }
        temp->next = startNode;
    }


    bool hasCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                return true;
            }
        }
        return false;
    }
    /* Function to print linked list */
    void print(ListNode* head)
    {
        ListNode* temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    void push(int data, ListNode* &head)
    {
        ListNode* temp = new ListNode(data);
        temp->next = head;
        head = temp;
    }

};

int main()
{
    /* Start with the empty list */
    ListNode* head = NULL;
    ListNode* l1;
    l1->push(5, head);
    l1->push(20, head);
    l1->push(4, head);
    l1->push(15, head);
    l1->push(85, head);
    l1->push(97, head);

    cout << "Given linked list\n";
    l1->print(head);

    l1->makeCycle(head,2);

    cout << endl<<"cycle present in linked list!! "<<l1->hasCycle(head)<<endl;
    return 0;
}

