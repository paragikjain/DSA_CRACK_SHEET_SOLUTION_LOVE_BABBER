#include <iostream>
using namespace std;

bool can_be_cooked(int rank[],int mid,int partha,int cook){
  int pc = 0; //paratha count;
  for(int i=0; i<cook;i++){
    int time = 0;
    int it = 1;
    while(time <mid){
      time = time + (rank[i]*it);
      it++;
      if(time<=mid)
        pc++;
    }
  }
  if(pc>=partha){
    return true;
  }
  else{
    return false;
  }
}
int main(){
  int testcase;
  cin>>testcase;
    while(testcase--){
    int partha;
    int cook;
    cin>>partha>>cook;
    int rank[cook];
    for(int i=0;i<cook;i++)
      cin>>rank[i];
    //find minmum rank
    int min_rank=rank[0];
    for(int i=1;i<cook;i++)
    {
      if(rank[i]<min_rank)
        min_rank = rank[i];      
    }
    //find time taken by min  rank to cook n parathas
    int low = 0;
    int high = (min_rank*(partha*(partha+1))/2);

    //using binary search approch for finding minimum time between low to high
    int min_time;
    while(low<=high){
      int mid = low+((high-low)/2);
      if(can_be_cooked(rank,mid,partha,cook)){
        min_time = mid;
        high = mid -1;
      }
      else{
        low = mid+1;
      }
    }
    cout<<min_time<<endl;
  }
  return 0;
}