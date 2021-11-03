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
	ListNode* swapPairs(ListNode* head) {

		if (!head)
			return NULL;

		if (!head->next)
			return head;

		ListNode* prev = new ListNode();
		ListNode* newHead = prev;

		ListNode* curr = head;

		while (curr && curr->next) {
			ListNode* temp = curr->next->next;
			curr->next->next = curr;
			prev -> next = curr->next;
			curr->next = temp;
			prev = curr;
			curr = temp;
		}

		return newHead->next;
	}
};