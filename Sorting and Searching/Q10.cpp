//we can do this using Map also Please try to figure out By Yourself
#include<iostream>

using namespace std;
//we can do this using Map also Please try to figure out By Yourself
void solution()
{
 int diff,n;
 cin>>n;
 cin>>diff;
 int a[n];
 for(int i=0;i<n;i++){
     cin>>a[i];
 }
 for(int i=0;i<n-1;i++)
 {
     for(int j=i;j<n;j++){
         if(abs(a[i]-a[j])==abs(diff)){
           cout<<1<<endl;
           return;
         }
     }
 }
 
 cout<<-1<<endl;
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

//we can do this using Map also Please try to figure out By Yourself