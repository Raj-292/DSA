/*
    For Input:
        1 4 N 4 2

    Your Output is:
        1 $ 4 $ 4 2 $ $ $

*/



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<vector<int>> levelOrder(struct Node* node);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<vector<int>> vec = levelOrder(root);
        for (vector<int> v : vec) {
            for (int value : v) {
                cout << value << " ";
            }
            cout << "$ ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


vector<vector<int>> helper(Node* node) {

    vector<vector<int>> res;

    queue<Node*> q;

    q.push(node);
    res.push_back({node->data});

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        vector<int> temp;

        //visiting all the children of the front node
        if (front->left) {
            q.push(front->left);
            temp.push_back(front->left->data);
        }

        if (front->right) {
            q.push(front->right);
            temp.push_back(front->right->data);
        }


        //if(temp.size()>0)
        res.push_back(temp);
    }


    return res;
}


//Function to return the level order traversal line by line of a tree.
vector<vector<int>> levelOrder(Node* node) {

    return helper(node);

}


/*

    @Uncommented if(temp.size()>0)


    For Input:
        1 4 N 4 2

    Your Output is:
        1 $ 4 $ 4 2 $

    But for test case :

        Input:

        7 5 3 6 2 N 1 11 11 6 13 N 6 6 12

        Its Correct output is:

        7 $ 5 3 $ 6 2 1 $ 11 11 6 13 6 $ 6 12 $

        And Your Code's output is:

        7 $ 5 3 $ 6 2 $ 1 $ 11 11 $ 6 13 $ 6 $ 6 12 $

*/



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<vector<int>> levelOrder(struct Node* node);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<vector<int>> vec = levelOrder(root);
        for (vector<int> v : vec) {
            for (int value : v) {
                cout << value << " ";
            }
            cout << "$ ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


vector<vector<int>> helper(Node* node) {

    vector<vector<int>> res;

    queue<Node*> q;

    q.push(node);
    res.push_back({node->data});

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        vector<int> temp;

        //visiting all the children of the front node
        if (front->left) {
            q.push(front->left);
            temp.push_back(front->left->data);
        }

        if (front->right) {
            q.push(front->right);
            temp.push_back(front->right->data);
        }


        //if(temp.size()>0)
        res.push_back(temp);
    }


    return res;
}


//Function to return the level order traversal line by line of a tree.
vector<vector<int>> levelOrder(Node* node) {

    return helper(node);

}




/*
    Previously, all the nodes at one level were not taken into a single vector, instead they were being taken as separate
    vectors on the basis of their parent.
    Hence, for all the nodes at one level to be taken in a single vector, we need to wait for all the parent nodes to be process
    For this purpose, (while(n--)) is added

    $ : AC

*/



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<vector<int>> levelOrder(struct Node* node);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        vector<vector<int>> vec = levelOrder(root);
        for (vector<int> v : vec) {
            for (int value : v) {
                cout << value << " ";
            }
            cout << "$ ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


vector<vector<int>> helper(Node* node) {

    vector<vector<int>> res;

    queue<Node*> q;

    q.push(node);
    res.push_back({node->data});

    while (!q.empty()) {

        int n = q.size();
        vector<int> temp;

        while (n--) {
            Node* front = q.front();
            q.pop();

            if (front->left) {
                q.push(front->left);
                temp.push_back(front->left->data);
            }

            if (front->right) {
                q.push(front->right);
                temp.push_back(front->right->data);
            }

        }

        if (temp.size() > 0)
            res.push_back(temp);

    }


    return res;
}


//Function to return the level order traversal line by line of a tree.
vector<vector<int>> levelOrder(Node* node) {

    return helper(node);

}



