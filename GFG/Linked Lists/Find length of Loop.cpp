/*
	First detect the loop. At the point where slow and fast meet, keeping moving fast by 1 and increment count while keeping slow as it is.
	when fastPtr->next becomes slowPtr, break and return the count.
	$ :  AC
*/

int countNodesinLoop(struct Node *head) {
	// Code here

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
		return 0;

	int cnt = 1;
	while (fastPtr->next != slowPtr) {
		fastPtr = fastPtr->next;
		cnt++;
	}

	return cnt;
}