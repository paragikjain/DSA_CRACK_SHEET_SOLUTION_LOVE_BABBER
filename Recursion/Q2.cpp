#include <iostream>
using namespace std;

void print_array(int a[],int start,int end){
  if(start==end){
    cout<<a[start]<<endl;
    return;
  }
  print_array(a,start+1,end);
  cout<<a[start]<<endl;
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  print_array(a,0,n-1);
  return 0;
}