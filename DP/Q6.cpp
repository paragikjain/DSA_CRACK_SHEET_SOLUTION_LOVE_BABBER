#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
#define W 100
#define H 100
int mat_mul_chain(int a[],int i, int j,int out[W][H]){
  if(i>=j)
    return 0;
  int val = INT_MAX;
  if(out[i][j]!=-1)
    return out[i][j];
  for(int k=i;k<j;k++)
  {
    out[i][j] = mat_mul_chain(a,i,k,out) + mat_mul_chain(a,k+1,j,out) + a[i-1] * a[k] * a[j];
    if(val>out[i][j]){
      val = out[i][j];
    }
  }
  return out[i][j];
}

int main(){
  int n;
  cin>>n;
  int a[n];
  int out[W][H];
  memset(out,-1,sizeof(out));
  for(int i=0;i<n;i++)
    cin>>a[i];
   
  //recursive function call
  cout<<mat_mul_chain(a,1,n-1,out);
  return 0;
}