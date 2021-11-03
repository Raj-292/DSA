/*
	When a vector is not initialized and some index of that vector is used/referenced, we get the error :
	Line 1034: Char 9: runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
	SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:9
*/

// Constructing an outdegree vector
vector<int> outdegree();
for (int i = 0 ; i < graph.size() ; i++) {
	outdegree[i] = graph[i].size();
}