#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }

    ListNode(int v) {
        val = v;
        next = NULL;
    }

};

class LinkedList
{
    ListNode *head = NULL;

public:
    void printListNode()
    {
        ListNode *temp = head;

        while (temp != NULL)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;

        cout << endl;
    }

    void getLinkedList(int n)
    {
        ListNode *dummyHead;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
            temp->val = x;
            temp->next = NULL;

            if (head == NULL)
            {
                head = temp;
                dummyHead = temp;
            }
            else
            {
                dummyHead->next = temp;
                dummyHead = dummyHead->next;
            }
        }
    }

    void reverse()
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *temp;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
    }

    ListNode *getMid()
    {

        if (head == NULL)
            return NULL;

        ListNode *temp = head;

        ListNode *fast = head, *slow = head;

        while (fast != NULL and fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void insertAt(int i, int v)
    {
        ListNode *temp = head;
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));

        node->val = v;
        node->next = NULL;

        int cnt = 0;

        while (temp->next != NULL)
        {

            if (cnt == i - 1)
            {
                break;
            }

            temp = temp->next;
            cnt++;
        }

        ListNode *k = temp->next;
        temp->next = node;
        node->next = k;
    }

    void removeAt(int i)
    {
        ListNode *temp = head;
        int cnt = 0;

        if(i == 0) {
            head = head->next;
            return;
        }

        while (temp->next != NULL)
        {
            if (cnt == i - 1)
            {
                break;
            }

            temp = temp->next;
            cnt++;
        }

        if (temp->next != NULL)
        {
            temp->next = temp->next->next;
        }
    }

    bool isEmpty() {
        return head == NULL;
    }

};

int main()
{
    int n;
    cin >> n;

    LinkedList l;
    l.getLinkedList(n);

    int t;
    cin >> t;

    // l.reverse();
    // ListNode* mid = l.getMid();
    // cout << mid->val << endl;

    l.removeAt(t);
    l.printListNode();
}