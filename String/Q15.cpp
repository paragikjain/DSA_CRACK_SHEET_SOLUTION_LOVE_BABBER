#include<iostream>

using namespace std;

void reverse(int a[],int low,int high){
    int mid=(low+high)/2;
    int count=0;
    for(int i=low;i<=mid;i++){
        int tmp=a[i];
        a[i]=a[high-count];
        a[high-count]=tmp;
        count++;
    }
}

void solution()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //finding element from backward direction
   int i;
   for(i=n-2;i>=0;i--){
       if(a[i]<a[i+1]){
           break;
       }
   }
   if(i==-1){
      reverse(a,0,n-1);
      for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
   }
   else
   {  int index0=i;
      int tmp_max=100000;
      int tmp_max_index=-1;
      i=i+1;
      while(i<n){
          if(a[index0]<a[i] && a[i]<tmp_max){
              tmp_max=a[i];
              tmp_max_index=i;
          }
          i++;
      }
      swap(a[index0],a[tmp_max_index]);
      reverse(a,index0+1,n-1);
      //cout<<index0<<" "<<tmp_max_index<<endl;
      for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
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