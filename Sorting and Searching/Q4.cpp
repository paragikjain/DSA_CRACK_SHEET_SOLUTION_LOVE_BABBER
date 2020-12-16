// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
  public:
    int countSquares(int N) {
        int count=0;
        int Max_sq=1;
        int i=1;
        while(Max_sq<N){
            Max_sq = i*i;
            i++;
            if(Max_sq<N)
              count++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends