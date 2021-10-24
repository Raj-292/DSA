/*
    $ : AC
*/

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        ListNode* newHead = new ListNode();
        ListNode* ptr3 = newHead;


        while (ptr1 && ptr2) {

            if (ptr2->val > ptr1->val) {
                ptr3->next = ptr1;
                ptr3 = ptr3->next;
                ptr1 = ptr1 -> next;
            } else {
                ptr3->next = ptr2;
                ptr3 = ptr3->next;
                ptr2 = ptr2 -> next;
            }
        }

        // Different size
        while (ptr1) {
            ptr3->next = ptr1;
            ptr3 = ptr3->next;
            ptr1 = ptr1 -> next;
        }

        while (ptr2) {
            ptr3->next = ptr2;
            ptr3 = ptr3->next;
            ptr2 = ptr2 -> next;
        }

        return newHead->next;
    }
};

/*
    In the above soln, no need of running while loop. We can just attach whichver amongst ptr1 & ptr2 is Not NULL directly.
    $ : AC
*/

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        ListNode* newHead = new ListNode();
        ListNode* ptr3 = newHead;


        while (ptr1 && ptr2) {

            if (ptr2->val > ptr1->val) {
                ptr3->next = ptr1;
                ptr3 = ptr3->next;
                ptr1 = ptr1 -> next;
            } else {
                ptr3->next = ptr2;
                ptr3 = ptr3->next;
                ptr2 = ptr2 -> next;
            }
        }

        // Different size
        if (ptr1) {
            ptr3->next = ptr1;
        }

        if (ptr2) {
            ptr3->next = ptr2;
        }

        return newHead->next;
    }
};