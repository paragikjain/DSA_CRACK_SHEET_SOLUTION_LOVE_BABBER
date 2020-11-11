 #include <bits/stdc++.h>
using namespace std;
int main(){
  char a[100],b[100];//="geeks for geeks";
  cin.getline(a,sizeof(a));
  cin.getline(b,sizeof(b));
  //find first element of a in b
  int first=0;
  while(a[first]!='\0'){
    if(a[0]==b[first]){
      break;
    }
    first++;
  }
  
  int i=0;
  while(a[i]!='\0'){
    if(b[first]=='\0'){
      first=0;
      continue;
    }   
    if(a[i]!=b[first]){
      cout<<0;
      //cout<<a[i]<<b[first];
      return 0;
    }
   first++;
    i++;
  }
  cout<<1;
  return 0;
}