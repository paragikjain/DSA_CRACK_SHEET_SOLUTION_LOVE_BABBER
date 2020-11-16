#include <iostream>
using namespace std;

void print_array(int a[],int n){
  if(n==0){
    cout<<a[0]<<endl;
    return;
  }
  print_array(a,n-1);
  cout<<a[n]<<endl;
}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  print_array(a,n-1);
  return 0;
}