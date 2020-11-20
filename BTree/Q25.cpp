#include<bits/stdc++.h>

using namespace std;

int solution()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int> v1[nodes];
  vector<int> v2[nodes];
  //connecting edges with nodes.
  for(int i=0;i<edge;i++){
      int n,e;
      cin>>n>>e;
      v1[n].push_back(e);
  }
  for(int i=0;i<edge;i++){
      int n,e;
      cin>>n>>e;
      v2[n].push_back(e);
  }
 
  for(int i=0;i<nodes;i++){
      reverse(v2[i].begin(),v2[i].end());
  }
  
   for(int i=0;i<nodes;i++){
     if(v1[i]!=v2[i]){
        return 0;   
     }
  } 
  return 1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solution()<<endl;
        
    }
}