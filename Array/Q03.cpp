//better use c++ sort function although it uses quick sort but it is 30% faster then quick sort function due to internal optimization of datatypes.

#include<iostream>

using namespace std;
int k;
int findpivot(int a[],int start,int end){
  int pivot =a[end-1];
  int index=start;
  for(int i=start;i<end-1;i++){
    if(a[i]<=pivot){
      int tmp=a[index];
      a[index]=a[i];
      a[i]=tmp;
      index++;
    }
  }
  int tmp=a[index];
  a[index]=a[end-1];
  a[end-1]=tmp;
  return index;
}

void quicksort(int a[],int start,int end){
  if(start>=end-1 || start>k )
    return;
  int pindex=findpivot(a,start,end);
  quicksort(a,start,pindex);
  quicksort(a,pindex,end);
}

void solution()
{
  
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  cin>>k;
  quicksort(a,0,n);
  cout<<a[k-1]<<endl;
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solution();
        
    }
}