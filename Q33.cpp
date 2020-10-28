#include<iostream>

using namespace std;

void solution()
{
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
      cin>>a[i];    
    }
    cin>>x;
    //fiding total element less or equal to cx
    int total_ele_less_then_x=0;
    for(int i=0;i<n;i++){
        if(a[i]<=x){
            //cout<<i<<endl;
            total_ele_less_then_x++;
        }
    }
    
    if(total_ele_less_then_x==1){
        cout<<0<<endl;
        return;
    }
    if(total_ele_less_then_x==n){
        cout<<0<<endl;
        return;        
    }

    //need to find subarray of size    total_ele_less_then_x which has maxmium  element less then x
     //this part can be optimize further
     int max_ele=0;
     
     for(int i=0;i<=n-total_ele_less_then_x;i++){
         int tmp=0;
         for(int j=i;j<i+total_ele_less_then_x;j++){
           if(a[j]<=x){
               tmp++;
           }  
         }
         if(tmp>max_ele){
             max_ele=tmp;
         }
     }
     
     cout<<total_ele_less_then_x-max_ele<<endl;
    
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