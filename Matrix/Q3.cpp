// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        int a[r];
        //filling col index array with 0
        for(int i=0;i<r;i++)
          a[i]=0;
        int prev=-1,min=100001,count=0,mid_no=((r*c)/2)+1;
        while(count<mid_no){
            min=100001;
          for(int i=0;i<r;i++){
            if(a[i]<c){
                if(matrix[i][a[i]]<min){
                    min=matrix[i][a[i]];
                    a[i]++;
                    if(prev!=-1){
                        a[prev]--;
                    }
                    prev=i;
                }
            }
          }
          prev=-1;
          count++;
          //cout<<min<<" "<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        }
        //cout<<endl;
        return min;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends