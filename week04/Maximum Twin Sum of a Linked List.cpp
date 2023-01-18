
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

    int pairSum(ListNode* head)
    {
        int mxSum = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* currentNode = slow;
        ListNode* prevNode = NULL;
        while(currentNode)
        {
            auto nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        currentNode = prevNode;
        ListNode* start = head;
        while(prevNode)
        {
            int sum = prevNode->val + start->val;
            mxSum = max(mxSum,sum);
            start = start->next;
            prevNode = prevNode->next;
        }

        prevNode = NULL;
        while(currentNode)
        {
            auto nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return mxSum;
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
    l1->push(35, head);
    l1->push(97, head);

    cout << "Given linked list\n";
    l1->print(head);

    int ans = l1->pairSum(head);

    cout << endl<<"maximum twin sum in linked list!! "<<ans<<endl;
    return 0;
}

