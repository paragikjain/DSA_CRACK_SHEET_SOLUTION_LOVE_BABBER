// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       //declaring dp table for storing subproblems outcome.
       long long int dp[m][n+1];
       //init dp col1 for coin sum 0
       for(int i=0;i<m;i++)
          dp[i][0] = 1;
        //init dp row 1 for first coin
        for(int i=1;i<n+1;i++){
          if(i%S[0] == 0)
            dp[0][i] = 1;
          else
            dp[0][i] =  0; 
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n+1;j++)
            {
                if(S[i]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-S[i]];
                }
            }
        }
    
    //   for(int i=0;i<m;i++){
    //       for(int j=0;j<n+1;j++){
    //           cout<<dp[i][j]<<"\t";
    //       }
    //       cout<<endl;
    //   }    
      return dp[m-1][n];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends