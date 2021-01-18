//Not Optimized version
// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends



#define mod 1000000007
class Solution{
    public:
    long long solution(int n, int t,int k)
    {
        if(n == 0)
          return 1;
        long long out = 0;
        if(t==0){
            //cout<<"here0"<<endl;
            out = out + (solution(n-1,t+1,k)%mod);
            for(int i=1;i<k;i++)
              out = out +(solution(n-1,0,k)%mod);
        }
        else{
            //cout<<"here1"<<endl;
          for(int i=1;i<k;i++)
              out = out + (solution(n-1,0,k)%mod);
        }
        return out;
        
    }
    long long countWays(int n, int k){
        return k*(solution(n-1,0,k)%mod);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends