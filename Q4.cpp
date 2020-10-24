#include<iostream>

using namespace std;

void solution()
{
  int n,zeroes=0,ones=0,twoes=0;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
      if(a[i]==0){
          zeroes++;
      }
      if(a[i]==1){
          ones++;
      }
      if(a[i]==2){
          twoes++;
      }      
  }
  for(int i=0;i<zeroes;i++)
    cout<<0<<" ";
  for(int i=0;i<ones;i++)
    cout<<1<<" ";
  for(int i=0;i<twoes;i++)
    cout<<2<<" ";    
  cout<<endl;
    
}

int main()
{
    int t; //testcase
    cin>>t;
    while(t--)
    {
        solution();
        
    }
}