/*
    Using a visited array
    $ : AC
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* helperDFS(Node* node, unordered_map<Node*, Node*>& mp, vector<bool>& visited) {

        // Base case.
        if (!node) {
            return NULL;
        }

        // Creating a new node.
        Node* newNode = new Node(node->val);

        // Creating a vector to hold the new neighbors
        vector<Node*> nbrArray;

        mp[node] = newNode;
        visited[node->val] = true;

        // Going through the neighbours
        for (Node* nbr : node->neighbors) {
            if (!visited[nbr->val]) {
                nbrArray.push_back(helperDFS(nbr, mp, visited));
            } else if (mp[nbr] != NULL) {
                nbrArray.push_back(mp[nbr]);
            }
        }

        // Link the new neighbours array to the new Node
        newNode->neighbors = nbrArray;

        return newNode;
    }

    Node* cloneGraph(Node* node) {

        // Visited array
        // Each node is uniquely identified by their val
        vector<bool> visited(101, false);

        unordered_map<Node*, Node*> mp;

        return helperDFS(node, mp, visited);

    }
};

/*
    Without using visited array
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* helperDFS(Node* node, unordered_map<Node*, Node*>& mp) {

        // Base case.
        if (!node) {
            return NULL;
        }

        // Creating a new node.
        Node* newNode = new Node(node->val);

        // Creating a vector to hold the new neighbors
        vector<Node*> nbrArray;

        mp[node] = newNode;

        // Going through the neighbours
        for (Node* nbr : node->neighbors) {
            if (mp[nbr] == NULL) {
                nbrArray.push_back(helperDFS(nbr, mp));
            } else {
                nbrArray.push_back(mp[nbr]);
            }
        }

        // Link the new neighbours array to the new Node
        newNode->neighbors = nbrArray;

        return newNode;
    }

    Node* cloneGraph(Node* node) {

        // Keeping a map of oldNode->newNode
        unordered_map<Node*, Node*> mp;

        return helperDFS(node, mp);

    }
};