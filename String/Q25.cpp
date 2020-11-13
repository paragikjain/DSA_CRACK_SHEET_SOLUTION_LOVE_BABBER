# include<bits/stdc++.h>
using namespace std;
int main(){
  int pat_size=5,text_size=19;
  char text[1000]="xndiaindiaidiaindia",pattern[1000]="india";
  // cin>>pat_size;
  // cin>>text_size;
  // gets(text);
  // gets(pattern);
  int i=pat_size-1;
  
  while(i<text_size)
  {
    int breaked=0;
    //cout<<i<<endl;
    int tmp=pat_size;
    for(int j=i;j>i-pat_size;j--){
      if(text[j]==pattern[tmp-1]){
        tmp--;
        continue;
      }
      else{
        int count=0;
        while(tmp>=0 && text[j]!=pattern[tmp-1]){
          //cout<<"here"<<count<<text[j]<<pattern[tmp-1]<<endl;
          count++;
          tmp--;
        }
        //cout<<i<<count<<endl;
        i=i+count;
        breaked=1;
        break;
      }
    }
    if(breaked==0){
      cout<<"pattern found:"<<i-(pat_size-1)<<endl;
      i++;
    }
  }
  return 0;
}