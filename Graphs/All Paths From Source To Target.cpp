
//Graph + Backtracking Question

class Solution {
public:

    vector<vector<int>> helper(vector<vector<int>>& graph, vector<bool>& visited, int curr) {

        //base case
        if (curr == graph.size())
            return {{}};
        if (curr > graph.size())
            return {;

                    vector<vector<int>> res;

                    // get all paths from outward connnections and append current to it

                    visited[curr] = true ;

            for (auto nbr : graph[curr]) {
            if (!visited[nbr]) {
                    vector<vector<int>> v1 = helper(graph, visited, nbr);
                    //take all the elements in v1, add current element to each one and then push them in res
                    // for(auto x : v1) {
                    //     x.insert(x.begin(),curr);
                    // }

                    for (auto x : v1) {
                        res.push_back(x);
                    }
                }
            }

        //append curr to start

        for (int i = 0 ;  i < res.size() ; i++) {
        res[i].insert(res[i].begin(), curr);
        }

        return res;
               }


        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

            int n = graph.size();

            //visited array
            vector<bool> visited (n, false);

            return helper(graph, visited, 0);

        }
    };

// Trying to debubg the above code












    class Solution {
    public:

        vector<vector<int>> helper(vector<vector<int>>& graph, vector<bool>& visited, int curr) {

            //base case
            if (curr == graph.size() - 1)
                return {{curr}};
            if (curr > graph.size())
                return {{}};

            vector<vector<int>> res;

            // get all paths from outward connnections and append current to it

            visited[curr] = true ;

            for (auto nbr : graph[curr]) {
                if (!visited[nbr]) {
                    vector<vector<int>> v1 = helper(graph, visited, nbr);
                    //take all the elements in v1, add current element to each one and then push them in res
                    // for(auto x : v1) {
                    //     x.insert(x.begin(),curr);
                    // }

                    for (auto x : v1) {
                        res.push_back(x);
                    }
                }
            }

            //append curr to start

            for (int i = 0 ;  i < res.size() ; i++) {
                res[i].insert(res[i].begin(), curr);
            }

            return res;
        }


        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

            int n = graph.size();

            //visited array
            vector<bool> visited (n, false);

            return helper(graph, visited, 0);

        }
    };

// Dont know why but changing base case worked !!!
// Still failing some test cases


    class Solution {
    public:

        vector<vector<int>> helper(vector<vector<int>>& graph, vector<bool>& visited, int curr) {

            //base case
            if (curr == graph.size() - 1)
                return {{curr}};
            if (curr == graph.size())
                return {{}};

            vector<vector<int>> res;

            // get all paths from outward connnections and append current to it

            visited[curr] = true ;

            for (auto nbr : graph[curr]) {
                if (!visited[nbr]) {
                    vector<vector<int>> v1 = helper(graph, visited, nbr);
                    //take all the elements in v1, add current element to each one and then push them in res
                    // for(auto x : v1) {
                    //     x.insert(x.begin(),curr);
                    // }

                    for (auto x : v1) {
                        res.push_back(x);
                    }
                }
            }

            //append curr to start

            for (int i = 0 ;  i < res.size() ; i++) {
                res[i].insert(res[i].begin(), curr);
            }

            //unvisit the current elt before leaving
            visited[curr] = false;

            return res;
        }


        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

            int n = graph.size();

            //visited array
            vector<bool> visited (n, false);

            return helper(graph, visited, 0);

        }
    };

// Some test cases were failing because unvisiting the current was causing the answers which were multi level deep to be not considered.
// Accepted 100ms 34.9 MB
