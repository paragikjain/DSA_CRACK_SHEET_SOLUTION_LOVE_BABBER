// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	    int mini(int x, int y, int z) { return min(min(x, y), z); }
	    int solution(string s, string t){
	       //top down approch
	       int n =s.size();
	       int m = t.size();
	       int out[n+1][m+1];
	       for(int i=0;i<=n;i++){
    	       for(int j=0;j<=m;j++){
    	        if(i == 0)
    	          out[i][j] = j;
    	        else if(j==0)
    	          out[i][j] = i;
    	        else if(s[i-1] == t[j-1])
    	                out[i][j] = out[i-1][j-1];
                else{
                     out[i][j] = 1+ mini(out[i][j-1], //insert
                     out[i-1][j-1], //replace
                     out[i-1][j]);       //remove
                 }
    	       }
	        }

	        return out[n][m];
	     }

		int editDistance(string s, string t)
		{
		    return solution(s,t);
		}
		
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends