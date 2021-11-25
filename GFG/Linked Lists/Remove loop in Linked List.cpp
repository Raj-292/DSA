/*
	$ : WA
	I/P : 5
		  7 58 36 34 16
		  1
	O/P : 0
	Exp : 1
*/

class Solution
{
public:
	//Function to remove a loop in the linked list.
	void removeLoop(Node* head) {
		// code here
		// just remove the loop without losing any nodes

		Node* slowPtr = head;
		Node* fastPtr = head;

		// move slowPtr by 1 and fastPtr by 2
		while (fastPtr && fastPtr->next) {
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;

			// If they become equal, break
			if (slowPtr == fastPtr)
				break;
		}

		// If they are not equal no loop
		if (slowPtr != fastPtr)
			return;

		// If loop exists, place slowPtr on head and keep moving both by 1
		slowPtr = head;

		while (slowPtr->next != fastPtr->next) {
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next;
		}

		// Set fastPtr->next to NULL
		fastPtr->next = NULL;
	}

};

/*
	In a case where the whole LL is a loop, Fast and slow both meet at head itself.
	In such a case, keep moving fast ptr by 1 as long as fastPtr->next != slowPtr, then assign fastPtr->next = NULL;
	$ : AC
*/

class Solution
{
public:
	//Function to remove a loop in the linked list.
	void removeLoop(Node* head) {
		// code here
		// just remove the loop without losing any nodes

		Node* slowPtr = head;
		Node* fastPtr = head;

		// move slowPtr by 1 and fastPtr by 2
		while (fastPtr && fastPtr->next) {
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;

			// If they become equal, break
			if (slowPtr == fastPtr)
				break;
		}

		// If they are not equal no loop
		if (slowPtr != fastPtr)
			return;

		// If loop exists, place slowPtr on head and keep moving both by 1
		slowPtr = head;

		if (slowPtr == fastPtr) {
			while (fastPtr->next != slowPtr)
				fastPtr = fastPtr->next;
		} else {
			while (slowPtr->next != fastPtr->next) {
				slowPtr = slowPtr->next;
				fastPtr = fastPtr->next;
			}
		}

		// Set fastPtr->next to NULL
		fastPtr->next = NULL;
	}

};