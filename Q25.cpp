#include <iostream>
#include <math.h>
#include <unordered_map> 

using namespace std;
int main(){
  int n,k;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cin>>k;
  unordered_map<int, int> umap;
  for(int i=0;i<n;i++){
    umap[a[i]]++;
  }
  float  times=(float)n/(float)k;
  times=ceil(times);
  
  for (auto x : umap) 
  {
    if(x.second>=times){
      cout <<"No: "<< x.first << " Count " << x.second << endl; 
    }
  } 
  return 0;
}