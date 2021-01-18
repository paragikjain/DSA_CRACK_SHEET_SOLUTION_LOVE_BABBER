// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W 

#define r 1000
#define c 1000
int knapsol(int W,int wt[],int val[],int n,int dp[r][c]){
    if(W <= 0 || n<0)
      return 0;
    if(dp[n][W] != -1){
        return dp[n][W];
    }  
     if(wt[n]>W){
        dp[n][W] = knapsol(W,wt,val,n-1,dp); 
        return dp[n][W];
     }
     else{
         dp[n][W] = max(knapsol(W,wt,val,n-1,dp),val[n] + knapsol(W-wt[n],wt,val,n-1,dp));
         return dp[n][W];
     }
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int dp[r][c];
   memset(dp,-1,sizeof(dp));
   return knapsol(W,wt,val,n-1,dp);
}





// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends