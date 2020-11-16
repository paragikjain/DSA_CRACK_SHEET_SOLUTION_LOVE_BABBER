#include <iostream>
using namespace std;

bool is_pal(string str,int start, int end){
  if(start==end)
    return true;
  if(str[start]!=str[end])
    return false;
  return is_pal(str,start+1,end-1);
}

int main(){
  string str;
  cin>>str;
  if(is_pal(str,0,str.size()-1)){
    cout<<"sting is pailandrom"<<endl;
  }else{
    cout<<"string is not a pailandrom string";
  }
  return 0;
}