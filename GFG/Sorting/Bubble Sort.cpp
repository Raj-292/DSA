/*
	Compilation error :
		prog.cpp: In member function void Solution::bubbleSort(int*, int):
		prog.cpp:31:33: error: invalid conversion from int to int* [-fpermissive]
		                     swap(arr[ptr],arr[ptr+1]);
		                                 ^
		prog.cpp:8:6: note:   initializing argument 1 of void swap(int*, int*)
		 void swap(int *xp, int *yp)
		      ^
		prog.cpp:31:44: error: invalid conversion from int to int* [-fpermissive]
		                     swap(arr[ptr],arr[ptr+1]);
          .................

*/

// { Driver Code Starts
//Initial Template for C++

// C program for implementation of Bubble sort
#include <stdio.h>

// swapping the elements
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	//Function to sort the array using bubble sort algorithm.
	void bubbleSort(int arr[], int n) {
		// Your code here

		int passes = n - 1;

		for (int i = 0 ; i < passes ; i++) {
			foar(int ptr = 0 ; ptr < passes - i ; ptr++) {
				if (arr[ptr] > arr[ptr + 1])
					swap(arr[ptr], arr[ptr + 1]);
			}
		}

	}
};


// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[1000], n, T, i;

	scanf("%d", &T);

	while (T--) {

		scanf("%d", &n);

		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		Solution ob;

		ob.bubbleSort(arr, n);
		printArray(arr, n);
	}
	return 0;;
}  // } Driver Code Ends

/*
	$ : AC

*/

// { Driver Code Starts
//Initial Template for C++

// C program for implementation of Bubble sort
#include <stdio.h>

// swapping the elements
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	//Function to sort the array using bubble sort algorithm.
	void bubbleSort(int arr[], int n) {
		// Your code here

		int passes = n - 1;

		for (int i = 0 ; i < passes ; i++) {
			for (int ptr = 0 ; ptr < passes - i ; ptr++) {
				if (arr[ptr] > arr[ptr + 1]) {
					int a  = arr[ptr];
					int b = arr[ptr + 1];
					int c;
					c = a;
					arr[ptr] = b;
					arr[ptr + 1] = c;
				}
			}
		}

	}
};


// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[1000], n, T, i;

	scanf("%d", &T);

	while (T--) {

		scanf("%d", &n);

		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		Solution ob;

		ob.bubbleSort(arr, n);
		printArray(arr, n);
	}
	return 0;;
}  // } Driver Code Ends

/*
	Using the given swap method which expects int* and NOT int
	$ : AC
*/

// { Driver Code Starts
//Initial Template for C++

// C program for implementation of Bubble sort
#include <stdio.h>

// swapping the elements
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	//Function to sort the array using bubble sort algorithm.
	void bubbleSort(int arr[], int n) {
		// Your code here

		int passes = n - 1;

		for (int i = 0 ; i < passes ; i++) {
			for (int ptr = 0 ; ptr < passes - i ; ptr++) {
				if (arr[ptr] > arr[ptr + 1]) {
					swap(arr + ptr, arr + ptr + 1);
				}
			}
		}

	}
};


// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[1000], n, T, i;

	scanf("%d", &T);

	while (T--) {

		scanf("%d", &n);

		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		Solution ob;

		ob.bubbleSort(arr, n);
		printArray(arr, n);
	}
	return 0;;
}  // } Driver Code Ends