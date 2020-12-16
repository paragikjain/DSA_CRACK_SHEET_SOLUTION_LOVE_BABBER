// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
    
    map<int,int> umap;
    for(int i=0;i<size;i++)
    {
        umap[a[i]]++;
    }
    
    for(auto x:umap){
        if(x.second>size/2)
          return x.first;
    }
    
    return -1;
    
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends