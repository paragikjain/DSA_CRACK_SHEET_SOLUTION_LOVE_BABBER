// we will consider 0 as pivot as in quick sort we do . after finding pivot with help of pindex all negetive elements will go to one side
//and all posetive int will come other side

#include<iostream>
using namespace std;
int rearrange_with_piovt_0(int a[],int n){
  int pindex=0;
  int pivot=0;
  for(int i=0;i<n;i++){
    if(a[i]<0){
      int tmp=a[pindex];
      a[pindex]=a[i];
      a[i]=tmp;
      pindex++;
    }
    
  }
  return pindex;

}

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int pindex=rearrange_with_piovt_0(a,n);
  int pos=pindex;
  int neg=pindex;
  int flag=0;
  for(int i=1;i<n && pos<n && neg<n ;i++)
  {
    if(flag){
      int tmp=a[neg];
      a[neg]=a[i];
      a[i]=tmp;
      neg++;
      flag=0;
    }
    else{
      int tmp=a[pos];
      a[pos]=a[i];
      a[i]=tmp;
      pos++;
      flag=1;
    }
  }
  for(int i =0; i<n;i++){
    cout<<a[i]<<" ";
  }
  return 0;
}
