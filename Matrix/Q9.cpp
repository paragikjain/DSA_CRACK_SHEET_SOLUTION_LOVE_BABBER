// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
//this implementaion with not heap ,Learn it how to traverse element by element in sorted manner in row and colume sorted matrix; 
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends





int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int a[n]; //for storing postion of row for each colume
  //init position of row for 0th col= 1 and 1st col=0 and rest -1;
  if(n==1 || k==1){
      return mat[0][0];
  }
  a[0]=1;
  a[1]=0;
  for(int i=2;i<n;i++)
   a[i]=-1;
   int min_count = 1; //1 beacuse first element will be always 0;
   int ret;
   while(min_count<k){
       int tmp_min=INT_MAX;
       int col;
       for(int i=0;i<n;i++)
       {
           if(a[i]>=0 && a[i]<n){
               //cout<<"hi"<<endl;
               if(mat[a[i]][i]<tmp_min){
                 tmp_min=mat[a[i]][i];
                 col=i;   
               }
           }
       }
       if(col<n-1 && a[col]==0){
             a[col+1]=0;
       }
       a[col]=a[col]+1;
       ret=tmp_min;
       min_count++;
   }
   return ret;
}
