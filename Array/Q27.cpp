#include<iostream>
#include <unordered_map> 
#include<algorithm>

using namespace std;

void solution()
{
  int n,m;
  cin>>n>>m;
  int a[n],b[m];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  for(int i=0;i<m;i++){
      cin>>b[i];
  }
  
 unordered_map<int, int> map1;
 unordered_map<int, int> map2; 
  for(int i=0;i<n;i++){
      map1[a[i]]++;
  }
  for(int i=0;i<m;i++){
      map2[b[i]]++;
  }  
  int flag=0;
  for(auto a : map2){
      if(map1.count(a.first)>0){
          if(map1[a.first]>=map2[a.first])
          {
             continue;      
          }
          else{
            flag=1;
            break;
          }
      }
      else{
          flag=1;
          break;
      }
  }
  
  if(flag==1){
      cout<<"No"<<endl;
  }
  else{
      cout<<"Yes"<<endl;
  }
  
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