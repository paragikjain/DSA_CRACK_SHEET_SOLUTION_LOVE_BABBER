// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>

using namespace std;

#define ll long long 
ll findSubarray(vector<ll> , int );

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        
        cout << findSubarray(arr,n) << "\n";
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// arr : given array 
// n : size of the given array
ll findSubarray(vector<ll> arr, int n ) {
    unordered_map<ll,ll> umap;
    ll sum=0;
    ll count =0;
    for(ll i=0;i<n;i++){
        // cout<<arr[i]<<" "<<sum<<endl;
        sum=sum+arr[i];
        
        if(sum==0){
            count++;
        }
        if(umap[sum]){
            // cout<<"sum "<<sum<<" "<<umap[sum];
            count=count+umap[sum];
        }
        umap[sum]++;
    }
    return count;
}
