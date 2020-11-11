// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:		

		
	int lps(string s)
	{
	    int n=s.length();
	    int a[n]; //to store 
	    // Your code goes here
	    int j=0;
	    int i;
	    a[0]=0;
	    for(i=1;i<n;){
	        if(s[j]==s[i]){
	            a[i]=j+1;
	            i++;
	            j++;
	            continue;
	        }
	        else{
	            a[i]=0;
	           if(j==0){
	                i++;
	            }
	            j=a[j-1];//go to value of last j
	        }
	       
	    }
	   // for(int i=0;i<n;i++){
	   //     cout<<a[i]<<" ";
	   // }
	   // cout<<endl;
	    return a[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends