#include<iostream>

using namespace std;

void is_pal(int curr_start, int curr_end,int *prev_start,int* prev_end, string a){
    
    int prev_diff= *prev_end - *prev_start +1;
    int curr_diff=curr_end-curr_start+1;
    if(curr_diff<=prev_diff){
        return;
    }
    int dec=0;
    for(int i=curr_start;i<curr_start+(curr_diff/2);i++,dec++)
    {
        if(a[i]!=a[curr_end-dec]){
            return;
        }
        //cout<<a[i]<<" "<<a[curr_end-dec];
    }
    //cout<<curr_start<<" "<<curr_end<<endl;
    *prev_end =  curr_end;
    *prev_start = curr_start;
}

void solution()
{
 int prev_start=0,prev_end=0;
 string a;
 cin>>a;
 int n=a.size();
 for(int i=0;i<n;i++){
     for(int j=n-1;j>=i;j--)
     {
        if(a[i]==a[j]){
            //cout<<a[i]<<" "<<a[j]<<endl;
          is_pal(i,j,&prev_start,&prev_end,a);
        }
    }
 }
 
 //cout<<prev_start<<" "<<prev_end;
 for(int i=prev_start;i<=prev_end;i++){
     cout<<a[i];
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