//Rabin karp algorithm for finding pattern in string

#include <bits/stdc++.h>
#define TOTAL_CHAR 26

using namespace std;

int grep(string text, string pattern){
  int hash_pattern=0;
  int count=pattern.size()-1;

  //creating has for pattern
  for(int i=0;i<pattern.size();i++,count--){
    hash_pattern=hash_pattern+(pow(10,count)*(int)pattern[i]);
  }
  cout<<hash_pattern<<endl;

  //creating hash of first pattern in text
 int hash_txt=0;
 count=pattern.size()-1;
 for(int i=0;i<pattern.size();i++,count--){
    hash_txt=hash_txt+(pow(10,count)*(int)text[i]);
  }
  cout<<hash_txt<<endl;


  //comparing hash to txt to hash to pattern if it matches then compare next other wise will go ahead
  for(int i=0;i<=text.size()-pattern.size();i++){
   if(hash_txt==hash_pattern){
   //then compare words
     for(int j=0;j<pattern.size();j++){
       if(pattern[j]!=text[i+j]){
         break;
       }
       if(j==pattern.size()-1){
         cout<<"pattern found at index:"<<i<<endl;
       }
     }
  }

  
  //update text hash value
  hash_txt=((hash_txt*10)-((pow(10,(int)pattern.size()-1)*(int)text[i])*10))+(pow(10,0)*(int)text[i+(int)pattern.size()]);
  cout<<hash_txt<<endl;
  }
}

int main(){
  string text,pattern;
  cin>>text>>pattern;
  grep(text,pattern);
  return 0;
}