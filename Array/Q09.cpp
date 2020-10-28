// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int getMinDiff(int a[], int n, int k) {
        if(n==1)
          return 0;
        sort(a,a+n);
        //first element will be minmum and last will be max so 
        //adding k in first and substracting k in last so we can minmize difference
        //find the diff between min and max
        int diff=a[n-1]-a[0];
        int min=a[0]+k;
        int max=a[n-1]-k;
        //cout<<min<<" "<<max;
        //if after doing that there is change in min max we will swap it
        if(min>max){
            int temp=max;
            max=min;
            min=temp;
        }
        //cout<<min<<" "<<max<<endl;
        
        //for remaining element from 1 to n-2 we will add k and subtarct k and see after doing this
        //is there any impact to min max .if no we will contionou if yes then we will chcek how much 
        //the change is impacting min and max and whom it is impacting more accrdingly we will change
        //values of min and max.
        for(int i=1;i<n-1;i++){
          int add=a[i]+k;
          int sub=a[i]-k;
          //if we are adding definatly we will go towards max and vica versa
          if(max>=add || min<=sub)
          {
           continue;
          }
          //if above case is false that means by adding and subtracing we are changing current value
          //of min max so here we will find out whom it is impacting less. which directly means if we are
          //adding then it will become max so we will comapre to min and vica versa and which has less diff
          //we will take decison accordingly.
          //cout<<"check:"<<add-min<<" "<<max-sub;
          if(add-min>=max-sub){
              min=sub;
          } 
          else{
              max=add;
          }
          //cout<<min<<" "<<max<<endl;
        }
        //returing min between first diff and changes diff.
        if(diff<max-min)
          return diff;
        else
          return max-min;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends