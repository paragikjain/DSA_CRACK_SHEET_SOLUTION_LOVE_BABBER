#include<bits/stdc++.h>
using namespace std;
int main(){
  char a[100];
  unordered_map <char,int> dailer;
  dailer.insert({'a',1});
  dailer.insert({'b',11});
  dailer.insert({'c',111});
  dailer.insert({'d',2});
  dailer.insert({'e',22});
  dailer.insert({'f',222});
  dailer.insert({'g',3});
  dailer.insert({'h',33});
  dailer.insert({'i',333});
  dailer.insert({'j',4});
  dailer.insert({'k',44});
  dailer.insert({'l',444});
  dailer.insert({'m',5});
  dailer.insert({'n',55});
  dailer.insert({'o',555});
  dailer.insert({'p',6});
  dailer.insert({'q',66});
  dailer.insert({'r',666});
  dailer.insert({'s',7});
  dailer.insert({'t',77});
  dailer.insert({'u',777});
  dailer.insert({'v',7777});
  dailer.insert({'w',8});
  dailer.insert({'x',88});
  dailer.insert({'y',888});
  dailer.insert({'z',8888});

  cin.getline(a,sizeof(a));
  int i=0;
  while(a[i]!='\0'){
    cout<<dailer[a[i]];
    i++;
  }
  return 0;
}