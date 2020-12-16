#include<iostream>
 
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int low=0;
  int high=n-1;
  int out;
  while(low<=high){
    int mid = low + ((high-low)/2);
    if(mid==n-1){
      out = mid;
      break;
    }
    if(a[mid+1]<a[mid]){
      out = mid;
      break;
    }
    else if(a[mid]<a[low])
    {
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  cout<<out;
  return 0;
}