#include<iostream>

using namespace std;

void solution()
{
    int count=0;
    string str;
    cin>>str;
    int n=str.size();
    for(int i=0;i<n;i++){
        if(i%2==0 && str[i]!='0'){
            count++;
        }
        if(i%2!=0 && str[i]!='1'){
            count++;
        }
    }
    
    int count2=0;
    for(int i=0;i<n;i++){
        if(i%2==0 && str[i]!='1'){
            count2++;
        }
        if(i%2!=0 && str[i]!='0'){
            count2++;
        }
    }    
   if(count2<count)
    cout<<count2<<endl;
   else
    cout<<count<<endl;     
    
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