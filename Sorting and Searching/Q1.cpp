#include <bits/stdc++.h>

using namespace std;

void solution()
{
  int n;
  int x;
  cin>>n>>x;
  int a[n];
  int first=-1,last;
  for(int i=0;i<n;i++){
   cin>>a[i];
   if(a[i]==x && first ==-1){
     first=i;
     last =i;
   }
   else if(a[i]==x && first !=-1)
     last = i;
     
  }
  if(first==-1)
    cout<<first;
  else
    cout<<first<<" "<<last;
  cout<<endl;
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