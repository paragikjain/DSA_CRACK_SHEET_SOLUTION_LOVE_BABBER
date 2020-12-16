// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{
  public:
    int middle(int a, int b, int c){
      if ((a < b && b < c) || (c < b && b < a)) 
        return b; 
      else if ((b < a && a < c) || (c < a && a < b)) 
        return a; 
      else
        return c;       
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}  // } Driver Code Ends