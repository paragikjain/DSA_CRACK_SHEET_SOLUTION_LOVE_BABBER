#include<iostream>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int a[n][m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>a[i][j];
  //taking transpose of matrix;
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<m;j++)
    {
      int tmp=a[i][j];
      a[i][j]=a[j][i];
      a[j][i]=tmp;
    }
  }
  //changing i colume to n-1 col and so on
  for(int i=0;i<n/2;i++)
  {
    for(int j=0;j<m;j++){
     int tmp=a[j][i];
     a[j][i]=a[j][n-i-1];
     a[j][n-i-1]=tmp;
    }
  }
  //print matrix back
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
  
}