#include<iostream>
#include<unordered_map>
using namespace std;

void solution()
{
 int n,x;
 cin>>n>>x;
 int a[n];
 for(int i=0;i<n;i++){
     cin>>a[i];
 }
 unordered_map <int,int> umap;
 for(int i=0;i<n;i++){
     umap[a[i]]++;
 }
 int flag=0;
 for(int i=0;i<n-1;i++){
   for(int j=i+1;j<n;j++){
       int sum=a[i]+a[j];
       int rem= x-sum;
       if(a[i]==rem && a[j]==rem && umap.count(rem)>1){
          flag=1;  
          //cout<<a[i]<<" "<<a[j]<<" "<<sum<<" "<<rem;
          break;
       }
       if(umap.count(rem)>0 && a[i]!=rem && a[j]!=rem){
          flag=1;  
          //cout<<a[i]<<" "<<a[j]<<" "<<sum<<" "<<rem;
          break;
       }
       
   }
   if(flag==1){
       break;
   }
 } 
 cout<<flag<<endl;
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