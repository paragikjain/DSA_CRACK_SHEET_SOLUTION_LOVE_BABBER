// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       int *output=new int(2);
       int Exor = 0;
       map<int,int> umap;
       for(int i=0;i<n;i++){
            if(umap[arr[i]])
              output[0] = arr[i];
            else{
              umap[arr[i]]++;
              Exor=Exor ^arr[i];
            }
        }
        //find total xOR
        for(int i=1;i<=n;i++)
          Exor=Exor^i;
        
          output[1] = Exor;
        

        return output;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends