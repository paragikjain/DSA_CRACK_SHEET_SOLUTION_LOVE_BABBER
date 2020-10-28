#include<iostream>
#include<algorithm>

using namespace std;

void solution()
{
  int n,k;
  cin>>n;
  long long a[n];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  cin>>k;
  sort(a,a+n);
  long long min=10000000000;
  for(int i=0;i<=n-k;i++){
      long long tmp_min=a[i+(k-1)]-a[i];
      if(tmp_min<min){
          min=tmp_min;
      }
  }
  cout<<min<<endl;
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