/*
	Recursive
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

	ListNode* newHead;

	ListNode* helper(ListNode* node) {

		//base case

		if (!node) {
			return NULL;
		}

		// This will be the head of the reversed list
		if (!node->next) {
			newHead = node;
			return node;
		}

		//calling helper on rest of the list

		ListNode* tail = helper(node->next);
		tail->next = node;
		node->next = NULL;

		return node;

	}

	ListNode* reverseList(ListNode* head) {
		ListNode* tail =  helper(head);
		return newHead;
	}
};