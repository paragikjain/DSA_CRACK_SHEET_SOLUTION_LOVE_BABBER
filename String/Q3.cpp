#include <bits/stdc++.h>
using namespace std;
int main(){
  char a[100];//="geeks for geeks";
  cin.getline(a,sizeof(a));
  unordered_map <char,int> umap;
  int i=0;
  while(a[i]!='\0'){
    umap[a[i]]++;
    i++;
  }

  for(auto x: umap)
    cout<<x.first<<" "<<x.second<<endl;
  return 0;
}