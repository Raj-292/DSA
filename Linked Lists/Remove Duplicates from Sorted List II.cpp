/*
	Not checking the last node was returing the original list
	$ : WA
	I/P : [1,2,2]
	O/P : [1,2,2]
	Exp : [1]

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
	ListNode* deleteDuplicates(ListNode* head) {

		ListNode* dummyHead = new ListNode();
		ListNode* ptr1 = dummyHead;

		ListNode* currNode = head;
		ListNode* prevNode = new ListNode(-101);

		if (!head) {
			return NULL;
		}

		while (currNode->next) {

			if (currNode->val != prevNode->val && currNode->val != currNode->next->val) {
				ptr1 -> next = currNode;
				ptr1 = ptr1->next;
				prevNode = currNode;
				currNode = currNode->next;
			} else {
				prevNode = currNode;
				currNode = currNode->next;
			}

		}

		// Check for last node
		if (currNode->val != prevNode->val) {
			ptr1 -> next = currNode;
			ptr1 = ptr1->next;
		}

		return dummyHead->next;
	}
};

/*
	Added ptr1->next = NULL to avoid selecting non-eligible nodes
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
	ListNode* deleteDuplicates(ListNode* head) {

		ListNode* dummyHead = new ListNode();
		ListNode* ptr1 = dummyHead;

		ListNode* currNode = head;
		ListNode* prevNode = new ListNode(-101);

		if (!head) {
			return NULL;
		}

		while (currNode->next) {

			if (currNode->val != prevNode->val && currNode->val != currNode->next->val) {
				ptr1 -> next = currNode;
				ptr1 = ptr1->next;
				prevNode = currNode;
				currNode = currNode->next;
			} else {
				prevNode = currNode;
				currNode = currNode->next;
			}

		}

		// Check for last node
		if (currNode->val != prevNode->val) {
			ptr1 -> next = currNode;
			ptr1 = ptr1->next;
		}

		ptr1->next = NULL;

		return dummyHead->next;
	}
};