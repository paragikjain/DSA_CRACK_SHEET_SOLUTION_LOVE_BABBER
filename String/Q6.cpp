//vaild shuffle
#include<bits/stdc++.h>
using namespace std;
int main()
{
  string str="hello";
  string str2="india";
  string shuffle="indsahello";
  string concat= str+str2;
  //cout<<concat.size()<<" "<<str.size()<<" "<<str2.size();
  if(shuffle.size()!=concat.size()){
    cout<<0;
    return 0;
  }
  if(shuffle.find(str) != std::string::npos && shuffle.find(str2)!= std::string::npos)
  {
    //cout<<concat.find(str)<<endl;
    cout<<1;
    return 0;
  }
  //cout<<concat.find("hellx");
  cout<<0;
  return 0;
}