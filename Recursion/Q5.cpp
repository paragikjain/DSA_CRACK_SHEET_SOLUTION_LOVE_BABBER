#include <iostream>
using namespace std;

void print_combinations(int a[],int c[],int r,int start,int end,int index){
if(index==r)
{
  for(int i=0;i<r;i++)
    cout<<c[i]<<",";
  cout<<endl;
  return;
}
if(start>end){
  return;
}
  
  print_combinations(a,c,r,start+1,end,index);
  c[index]=a[start];
  print_combinations(a,c,r,start+1,end,index+1);

}

int main(){
  int n;
  cout<<"Enter The size of array"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter array elements"<<endl;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cout<<"Enter the group size"<<endl;
  int r;
  cin>>r;
  //array to store combinations
  int c[r];

  print_combinations(a,c,r,0,n-1,0);
  

}