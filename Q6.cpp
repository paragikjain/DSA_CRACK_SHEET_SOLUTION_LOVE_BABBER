//same type of algo we use in merge sort to merging two arrays
//we can do intersection in same way also
// if same arrya has repeted value the this progrme will not work 
//use can use set in c++ for converting into unique values
#include<iostream>

using namespace std;

void solution()
{
  int n,m;
  cin>>n;
  cin>>m;
  int a[n],b[m],c[n+m];
  for(int i=0;i<n;i++){
   cin>>a[i];    
  }
  for(int i=0;i<m;i++){
      cin>>b[i];
  }
  int i=0,j=0,index=0;
  while(i<n&&j<m){
      if(a[i]<b[j])
      {
          c[index]=a[i];
          ++i;
      }
      else if(a[i]>b[j]){
          c[index]=b[j];
          ++j;
      }
      else{
          c[index]=b[j];
          ++i;++j;
      }
      index++;
  }
  while(i<n){
      c[index]=a[i++];
      index++;
  }
  while(j<m){
      c[index]=b[j++];
      index++;
  }
  cout<<index<<endl;
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