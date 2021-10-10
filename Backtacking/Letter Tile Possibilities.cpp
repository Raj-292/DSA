/*
    $ : WA
*/

class Solution {
public:

    vector<string> getStartStrings(string& tiles, int idx) {

        // Base Case.
        if (idx == tiles.length())
            return {""};

        vector<string> startStrings;

        vector<string> next = getStartStrings(tiles, idx + 1);
        vector<string> nextCopy = next;

        // Include
        // Append current char to all strings in next
        for (string& s : nextCopy) {
            s += tiles[idx];
        }

        // Exclude
        // Do nothing

        // Combine next and nextcopy
        for (const string& s : next) {
            nextCopy.push_back(s);
        }

        return nextCopy;

    }

    int helper(string& str, int idx) {

        // Base Case.
        if (idx == str.size())
            return 0;

        int res = 0;

        // Recursive

        int nextRes = helper(str, idx + 1);

        // Anyone of the letters from idx ... size()-1 can be fixed to start
        for (int i = idx ; i < str.size() ; i++) {
            res++;
        }


        return res + nextRes;
    }

    int numTilePossibilities(string tiles) {
        vector<string> starts = getStartStrings(tiles, 0);
        for (const string& s : starts) {
            cout << "String of size: " << s.size() << "   : " <<  s << endl;
        }

        int finalAns = 0;

        for (string s : starts) {
            if (!s.size() == 0)
                finalAns += helper(s, 0);
        }

        return finalAns;
    }
};

/*
    WA, WIP
*/

class Solution {
public:

    vector<string> getStartStrings(string& tiles, int idx) {

        // Base Case.
        if (idx == tiles.length())
            return {""};

        vector<string> startStrings;

        vector<string> next = getStartStrings(tiles, idx + 1);
        vector<string> nextCopy = next;

        // Include
        // Append current char to all strings in next
        for (string& s : nextCopy) {
            s += tiles[idx];
        }

        // Exclude
        // Do nothing

        // Combine next and nextcopy
        for (const string& s : next) {
            nextCopy.push_back(s);
        }

        return nextCopy;

    }

    int helper(string& str, int idx) {

        // Base Case.
        if (idx == str.size())
            return 0;

        int res = 0;

        // Recursive

        int nextRes = helper(str, idx + 1);

        // Anyone of the letters from idx ... size()-1 can be fixed to start
        // for(int i = idx ; i < str.size() ; i++) {
        //     res++;
        // }


        return str.size() - idx + nextRes;
    }

    int numTilePossibilities(string tiles) {
        vector<string> starts = getStartStrings(tiles, 0);
        for (const string& s : starts) {
            cout << "String of size: " << s.size() << "   : " <<  s << endl;
        }

        int finalAns = 0;

        for (string s : starts) {
            if (!s.size() == 0) {
                int temp = helper(s, 0);
                finalAns += temp;
                cout << "For string : " << s << " temp ans : " << temp << endl;
            }

        }

        return finalAns;
    }
};

/*
    $ : AC
*/

class Solution {
public:

    void helper(string& tiles, vector<bool>& visited, set<string>& res, string& currSequence) {
        for (int i = 0 ; i < tiles.size() ; i++) {
            if (!visited[i]) {
                currSequence += tiles[i];
                res.insert(currSequence);
                visited[i] = true;
                helper(tiles, visited, res, currSequence);
                currSequence.pop_back();
                visited[i] = false;
            }
        }


    }

    int numTilePossibilities(string tiles) {
        vector<bool> visited(tiles.size(), false);

        set<string> res;
        string currSequence = "";
        helper(tiles, visited, res, currSequence);

        return res.size();

    }
};