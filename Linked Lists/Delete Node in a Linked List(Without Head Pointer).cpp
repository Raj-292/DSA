/*
	Without using head pointer
	$ : AC
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void deleteNode(ListNode* node) {

		ListNode* temp = node->next->next;
		int tempVal = node->next->val;

		node->val = tempVal;
		node->next = temp;
	}
};