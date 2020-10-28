#include<iostream>
#define MAX 2568
using namespace std;
/*
example 5!=5*4*3*2 so in multiply function we will pass one by one this values from 2 to 5 
in multiply function we will use same way how we multiply in daily life on paper
*/
int multiply(int result[],int res_size,int multipal){
    int carry=0;
    for(int i=0;i<=res_size;i++){
        int mul=multipal*result[i]+carry;
        result[i]=mul%10;
        carry=mul/10;
        //cout<<carry<<result[i]<<" size "<<res_size<<endl;
        
    }
    while(carry){
        res_size++;
        result[res_size]=carry%10;
        carry=carry/10;
    }
    
    return res_size;
    
}
void solution()
{
  int n;
  cin>>n;
  int result[MAX];
  int res_size=0;
  result[0]=1;
  for(int i=2;i<=n;i++)
  {
      res_size=multiply(result,res_size,i);
  }
  for(int i=res_size; i>=0;i--)
  {
      cout<<result[i];
  }
  cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solution();
        
    }
}