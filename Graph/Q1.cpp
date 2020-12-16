#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[],int u,int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void print(vector<int> adj[],int k)
{
for(int i=0;i<k;i++){
  cout<<i<<"is connected to : ";
  for(auto x: adj[i]){
    cout<<x<<"->";
  }
  cout<<endl;
}
}

int main(){
  int k = 5;
  vector<int> adj[k];
  addedge(adj,0,1);
  addedge(adj,0,4);
  print(adj,k);
  
  return 0;
}