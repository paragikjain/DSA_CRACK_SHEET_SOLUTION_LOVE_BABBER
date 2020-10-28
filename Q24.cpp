#include<iostream>
#include<algorithm>

using namespace std;

void solution()
{
  int n;
  cin>>n;
  int a[n];
  for (int i=0;i<n;i++){
      cin>>a[i];
  }
  sort(a,a+n);
  int max_count=1;
  int curr_count=1;
  for(int i=1;i<n;i++){
      if(a[i-1]==a[i]-1){
          curr_count++;
      }
      else if(a[i-1]==a[i]){
          continue;
      }
      else{
          curr_count=1;
      }
      if(curr_count>max_count){
          max_count=curr_count;
      }
  }
  cout<<max_count<<endl;
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