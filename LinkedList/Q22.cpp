// C++ implementation to count triplets in a sorted doubly linked list 
// whose sum is equal to a given value 'x' 
#include <bits/stdc++.h> 

using namespace std; 

// structure of node of doubly linked list 
struct Node { 
	int data; 
	struct Node* next, *prev; 
}; 

// function to count triplets in a sorted doubly linked list 
// whose sum is equal to a given value 'x' 
int countTriplets(struct Node* head, int x) 
{ 
	struct Node* ptr, *ptr1, *ptr2; 
	int count = 0; 

	// unordered_map 'um' implemented as hash table 
	unordered_map<int, int> um; 

	// insert the <node data, node pointer> tuple in 'um' 
	for (ptr = head; ptr != NULL; ptr = ptr->next) 
		um[ptr->data]++; 

	// generate all possible pairs 
	for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) 
		for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next) { 

			// p_sum - sum of elements in the current pair 
			int p_sum = ptr1->data + ptr2->data; 

			// if 'x-p_sum' is present in 'um' and either of the two nodes 
			// are not equal to the 'um[x-p_sum]' node 
			//if (um.find(x - p_sum) != um.end() && um[x - p_sum] != ptr1 
			//	&& um[x - p_sum] != ptr2) 

				// increment count 
				
				if(ptr1->data==x-p_sum || ptr2->data ==x-p_sum )
				  count=count+(um[x-p_sum]-1);
				else
				  count=count+um[x-p_sum];
		} 
		

	// required count of triplets 
	// division by 3 as each triplet is counted 3 times 
	return (count / 3); 
} 

// A utility function to insert a new node at the 
// beginning of doubly linked list 
void insert(struct Node** head, int data) 
{ 
	// allocate node 
	struct Node* temp = new Node(); 

	// put in the data 
	temp->data = data; 
	temp->next = temp->prev = NULL; 

	if ((*head) == NULL) 
		(*head) = temp; 
	else { 
		temp->next = *head; 
		(*head)->prev = temp; 
		(*head) = temp; 
	} 
} 

// Driver program to test above 
int main() 
{ 
	// start with an empty doubly linked list 
	struct Node* head = NULL; 

    // insert values in sorted order 
    insert(&head, 9); 
    insert(&head, 8); 
    insert(&head, 6); 
    insert(&head, 5); 
    insert(&head, 4); 
    insert(&head, 2); 
    insert(&head, 1); 

	int x = 17; 

	cout << "Count = "
		<< countTriplets(head, x); 
	return 0; 
} 
