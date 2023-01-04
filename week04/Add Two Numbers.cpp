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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode(INT_MIN, NULL);
        ListNode* temp = head;
        int carry=0;
        while(l1 || l2 || carry)
        {
            int sum = 0;
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
        }
        sum+=carry;
        carry = sum/10;
        ListNode* newNode = new ListNode(sum%10,NULL);
        temp->next = newNode;
        temp = temp->next;
    }
    return head->next;
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
    ListNode* head2 = NULL;

    ListNode* l1;

    l1->push(3, head);
    l1->push(4, head);
    l1->push(2, head);

    ListNode* l2;
    l2->push(4, head2);
    l2->push(6, head2);
    l2->push(5, head2);

    cout << "Given linked list1\n";
    l1->print(head);
    cout << "\nGiven linked list2\n";
    l2->print(head2);

    ListNode* l3;
    ListNode* head3 = l3->addTwoNumbers(head,head2);


    cout << endl<<"after addition new linked list!! "<<endl;
    l3->print(head3);
    return 0;
}

