#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int a[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
unordered_map <int,int> umap;

//filling all first row element to map
for(int j=0;j<m;j++){
  umap[a[0][j]]=1;
}

//for rest of row we will check that this element exist in next rows and if in some row if it is repeted we wont insert in map again
for(int i=1;i<n;i++){
  for(int j=0;j<m;j++){
    if(umap[a[i][j]]==i){
      umap[a[i][j]]++;
    //if it is last row print here only
      if(i==n-1)
        cout<<a[i][j]<<" ";
    }
  }
}
return 0;
}