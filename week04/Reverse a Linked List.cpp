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

    ListNode* reverseList(ListNode* head)
    {
        ListNode* currentNode = head;
        ListNode* prevNode = NULL;
        while(currentNode)
        {
            auto nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return prevNode;
    }

     /* Function to print linked list */
    void print(ListNode* head)
    {
         ListNode* temp = head;
        while (temp != NULL) {
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
    l1->push(20, head);
    l1->push(4, head);
    l1->push(15, head);
    l1->push(85, head);

    cout << "Given linked list\n";
    l1->print(head);

    head = l1->reverseList(head);

    cout << endl<<"Reversed linked list \n";
    l1->print(head);
    return 0;
}

