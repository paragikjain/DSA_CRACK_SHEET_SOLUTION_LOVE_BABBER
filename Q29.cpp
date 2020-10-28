#include<iostream>

using namespace std;

void solution()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  int right[n],left[n];//for storing biggest right to each index and left to each index
  right[0]=a[0];   //mistankely take left as right and right as left so will continue with same name
  left[n-1]=a[n-1];
  int biggest_right=a[0];
  int biggest_left=a[n-1];
  for(int i=1;i<n;i++){
      if(a[i-1]>biggest_right){
          biggest_right=a[i-1];
      }
      right[i]=biggest_right;
  }
  for(int i=n-2;i>=0;i--){
      if(a[i+1]>biggest_left){
          biggest_left=a[i+1];
      }
      left[i]=biggest_left;
  }
  /*for(int i=0;i<n;i++){
     cout<<right[i]<<" "<<a[i]<<" "<<left[i]<<endl;
  }*/
  //now calculating unit that i can store at each index
  int total_water=0;
  for(int i=0;i<n;i++){
      int min_from_lr=min(left[i],right[i]);
      if(min_from_lr-a[i]>0){
        total_water=total_water + (min_from_lr-a[i]);
      }
  }
  cout<<total_water<<endl;
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