// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    long long maxprod=arr[0],minprod=arr[0],maxprod_final=arr[0];
        //long long a=404928287208900000;
        //cout<<a;
        for(int i=1;i<n;i++){
            if(arr[i]<0){
            swap(maxprod,minprod);
            }
            long long v=arr[i];
            long long x=maxprod*v;
            long long y=minprod*v;
            // cout<<"i="<<i<<endl<<x<<endl<<y<<endl;
//
            maxprod=max(v,x);
            minprod=min(v,y);
            maxprod_final=max(maxprod_final,maxprod);
        }
        
	    return maxprod_final;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends