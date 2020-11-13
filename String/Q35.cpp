#include<iostream>
using namespace std;


//this is not optimized approch we can use LPS array of KMP algo for o(n) solution
int  is_pal(int start,int end,string a){
  int len=(end-start)/2,count=0;
  for(int i=start;i<start+len;i++){
     if(a[i]!=a[end-1-count]){
       return 0;
     }
     count++;
  }
  return 1;
}
int main(){
  string input;
  cin>>input;
  int len=input.size();
  int out;
  for(int i=len-1;i>=0;i--){
    if(is_pal(0,i+1,input)){
      out=i;
      break;
    }
  }
  cout<<len-(out+1);
  return 0;
}