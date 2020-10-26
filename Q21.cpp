// A C++ program to find if there is a zero sum 
// subarray 
// The idea is to iterate through the array and for every element arr[i], calculate sum of elements form 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, then there is a zero sum array. Hashing is used to store the sum values, so that we can quickly store sum and find out whether the current sum is seen before or not.
#include <bits/stdc++.h> 
using namespace std; 

bool subArrayExists(int arr[], int n) 
{ 
	unordered_set<int> sumSet; 

	// Traverse through array and store prefix sums 
	int sum = 0; 
	for (int i = 0 ; i < n ; i++) 
	{ 
		sum += arr[i]; 

		// If prefix sum is 0 or it is already present 
		if (sum == 0 || sumSet.find(sum) != sumSet.end()) 
			return true; 

		sumSet.insert(sum); 
	} 
	return false; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {-3, 2, 3, 1, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	if (subArrayExists(arr, n)) 
		cout << "Found a subarray with 0 sum"; 
	else
		cout << "No Such Sub Array Exists!"; 
	return 0; 
} 
