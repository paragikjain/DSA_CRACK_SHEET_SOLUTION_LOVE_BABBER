#include<iostream>

using namespace std;

void solution()
{
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  int sum=0,subarray_start=0,min_len=n+1;
  for(int i=0;i<n;i++){
      sum=sum+a[i];
      while(sum>x && subarray_start<=i){
          //cout<<i<<" "<<min_len<<" "<<subarray_start<<endl;
          if(min_len>(i+1)-subarray_start)
          { 
              min_len=(i+1)-subarray_start;
              //cout<<min_len<<endl;
              //cout<<i<<" "<<subarray_start<<endl;
          }
          sum=sum-a[subarray_start];
          subarray_start++;
      }

      
  }
  cout<<min_len<<endl;
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