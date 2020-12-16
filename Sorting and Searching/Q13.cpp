// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    //sort the array first
	    sort(arr,arr+n);
	    int count =0;
	    //run loop from 0 to n-2 cuz at last n-2 can make a triplet.
	    for(int i=0;i<n-1;i++){
	        int start=i+1;
	        int end =n;
	        //if sum of start and end is lesser then given sum that means inbetween element will be also
	        //lesser the so we will add end-start to count beacuse all possible combination will be counted.
	        // and same time we will increse the start.
	        //if that is not the case then we will decrese the end
	        while(start<end){
	            if(arr[i]+arr[start]+arr[end]<sum){
	                count=count+(end-start);
	                start=start+1;
	            }else{
	                end =end-1;
	            }
	        }
	    }
	    
	    return count;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends