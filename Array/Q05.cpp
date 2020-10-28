//we can use same algo to find pivot in quick sort
#include <iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int index=0;
  for(int i=0;i<n;i++){
    if(a[i]<0){
       int tmp=a[index];
       a[index]=a[i];
       a[i]=tmp;
       index++;
    }
  }
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}