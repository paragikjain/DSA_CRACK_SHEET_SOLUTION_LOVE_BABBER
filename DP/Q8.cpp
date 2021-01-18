// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int solution(int arr[], int N,int sum,int i){
        
        if(sum<0 || i>=N)
          return 0;
        
        if(sum == 0)
          return 1;
         
         return solution(arr,N,sum-arr[i],i+1) || solution(arr,N,sum,i+1);
         
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0;i<N;i++)
          sum = sum +arr[i];
        if(sum %2 != 0)
          return 0;
        else
          return solution(arr,N,sum/2,0); //sending half of sum beacuase one part should  half of sum
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends