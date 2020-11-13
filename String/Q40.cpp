#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
  int computer;
  cin>>computer;
  string customer;
  cin>>customer;
  map <char,int> umap;
  int count = 0;
  int out=0;
  for(int i=0;i<customer.size();i++){
    umap[customer[i]]++;
    if(umap[customer[i]]==1){
      count++;
      // cout<<count<<endl;
      if(count>computer){
        out++;
      }      
    }else{    
      count--;
    }

  }
  cout<<out;
  return 0;
}