///Time Complexity O(n) n is the number of nodes;
///Space Complexity O(n)

#include<bits/stdc++.h>
using namespace std;

class MyLinkedList
{
public:
    class Node
    {
    public:
        int data;
        Node* next;
        Node(int val, Node* nxt)
        {
            data = val;
            next = nxt;
        }
    };
    const static int DUMMYVALUE = INT_MIN;
    Node* head = NULL;
    int len;

    MyLinkedList()
    {
        len = 0;
        head = new Node(DUMMYVALUE, NULL);
    }

    int get(int index)
    {
        if(index<0 || index>=len)
            return -1;
        auto currentNode = head->next;
        while(index--)
        {
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }

    void addAtHead(int val)
    {
        addAtIndex (0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex (len, val);
    }

    void addAtIndex(int index, int val)
    {
        if(index<0 || index>len)
            return;
        auto currentNode = head;
        while(index--)
        {
            currentNode = currentNode->next;
        }
        auto nxt = currentNode->next;
        currentNode->next = new Node(val, NULL);
        currentNode->next->next = nxt;
        len++;
    }

    void deleteAtIndex(int index)
    {
        if(index<0 || index>=len)
            return;
        auto currentNode = head;
        while(index--)
        {
            currentNode = currentNode->next;
        }
        auto todelete = currentNode->next;
        currentNode->next = currentNode->next->next;
        delete (todelete);
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{
    int index = 0, val = 5;
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(index);
    cout<<param_1<<endl;
    obj->addAtHead(val);
    param_1 = obj->get(index);
    cout<<param_1<<endl;
    val = 6, index =1;
    obj->addAtTail(val);
    param_1 = obj->get(index);
    cout<<param_1<<endl;
    index = 1, val = 7;
    obj->addAtIndex(index,val);
    param_1 = obj->get(index);
    cout<<param_1<<endl;
    index = 0;
    obj->deleteAtIndex(index);
    param_1 = obj->get(index);
    cout<<param_1<<endl;
    return 0;
}
