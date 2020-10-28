// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {   
            vector<int> output;
            int second=0;
            int third=0;
            int prev_i=-10;
            for(int i=0;i<n1;i++)
            {
              if(prev_i==A[i]){
                continue;
              }
              prev_i=A[i];
              int found =0,found2=0;
              for(int j=second;j<n2;j++)
              {
                 if(A[i]==B[j])
                 {
                     second=j;
                     
                     found=1;
                     break;
                 }
                 if(A[i]<B[j])
                 {
                     second=j;
                     //cout<<"second:"<<A[i]<<" "<<B[j]<<endl;
                     break;
                 }
              }
              for(int k=third;k<n3 && found==1;k++)
              {
                 if(A[i]==C[k])
                 {
                     third=k;
                     //cout<<"third:"<<C[k]<<endl;
                     found2=1;
                     break;
                 }
                 if(A[i]<C[k])
                 {
                     third=k;
                     break;
                 }
                 
               }
              if(found2==1){
                  output.push_back(A[i]);
              } 
           }
            return output;
        }
       
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends