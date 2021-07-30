/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool helper(TreeNode* p, TreeNode* q) {
        //Trees will be same if the left sub-tree of p == left sub-tree of q
        // and right sub-tree of p == right sub-tree of q

        // if( (!p->left && !p->right) && (!q->left && !q->right)) {
        //     return true;
        // }  //This gives null pointer runtime error because there might be a case where either p or q becomes null and their left and right pointers are being accessed here.

        if (!p && !q) //This means that both have reached leaf node
            return true;

        if (!p || !q) //This means that one of them have reached leaf node
            return false;

        if (p->val != q->val)
            return false;

        return (helper(p->left, q->left) && helper(p->right, q->right));

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);
    }
};