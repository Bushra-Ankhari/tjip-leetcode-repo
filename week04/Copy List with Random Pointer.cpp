///Time Complexity O(n) n is the number of nodes;
///Space Complexity O(n)
#include<bits/stdc++.h>
using namespace std;


class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode* random;
    ListNode(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }

    ListNode* copyRandomList(ListNode* head)
    {
        ListNode* currNode = head;
        while(currNode)
        {
            ListNode* temp = currNode->next;
            currNode->next = new ListNode(currNode->val);
            currNode->next->next = temp;
            currNode = temp;
        }
        currNode = head;
        while(currNode != NULL)
        {
            if (currNode->next != NULL)
            {
                currNode->next->random = (currNode->random != NULL) ? currNode->random->next : NULL;
            }
            currNode = currNode->next->next;
        }
        ListNode* org = head;
        ListNode* cop = (head != NULL) ? head->next : NULL;
        ListNode* temp = cop;
        while(org!=NULL)
        {
            org->next = org->next->next;
            cop->next = (cop->next != NULL) ? cop->next->next  : cop->next;
            org = org->next;
            cop = cop->next;
        }
        return temp;
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
    ListNode l1(1);
    l1.push(5, head);
    l1.push(20, head);
    l1.push(4, head);
    l1.push(15, head);
    l1.push(85, head);
    l1.push(97, head);
    cout << "Given linked list\n";
    l1.print(head);
    head = l1.copyRandomList(head);
    cout << endl<<"cycle present in linked list!!"<<endl;
    l1.print(head);
    return 0;
}


