/*
    Using Hashmap.
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
    bool hasCycle(ListNode *head) {

        // Map to store the addresses of nodes
        unordered_map<ListNode*, int> mp;

        mp[head]++;

        while (head) {
            head = head->next;
            mp[head]++;
            if (mp[head] == 2)
                return true;
        }

        return false;
    }
};