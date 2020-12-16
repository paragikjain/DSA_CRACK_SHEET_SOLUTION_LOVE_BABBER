// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

//inversion means if element of right array is  greater how many elemnents from left array so 
// we will do n1-i beacuse till i all left array already we checked it is smaller
//example      : 2,4,1,3,5
//inversion 1  : 2,1,4,3,5
//inversion 2  : 2,1,3,4,5
//inversion 3  : 1,2,3,4,5


long long merge(long long left[], long long right[],long long arr[],long long n1,long long n2){
  int i=0,j=0,k=0;
  int inv_count = 0; 
  while(i<n1 && j<n2){
      if(left[i]<=right[j]){
        arr[k] = left[i];
        i++;
      }
      else{
          inv_count = inv_count + (n1 - i);
          arr[k] = right[j];
          j++;
      }
      k++;
  }
  
 while(i<n1){
     arr[k] = left[i];
     i++;
     k++;
 }
 
  while(j<n2){
     arr[k] = right[j];
     j++;
     k++;
 }
 return inv_count;
}

long long mergesort(long long arr[],long long N){
    if(N<=1)
      return 0;
    long long invcount = 0;
    long long mid = N/2;
    long long left[mid];
    long long right[N-mid];
    for(int i=0;i<mid;i++)
     left[i] = arr[i];
    for(int i=mid;i<N;i++)
     right[i-mid] = arr[i];
     
     invcount += mergesort(left,mid);
     invcount += mergesort(right,N-mid);
     invcount +=merge(left,right,arr,mid,N-mid);
     return invcount;
     
     
}

long long int inversionCount(long long arr[], long long N)
{
    return mergesort(arr,N);
    // for(int i =0;i<N;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends