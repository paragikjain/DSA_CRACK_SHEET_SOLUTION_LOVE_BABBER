// { Driver Code Starts
// Initial template for C++


#include<bits/stdc++.h>
using namespace std;


int findPages(int arr[], int n, int m);

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        cout << findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//User function template in C++

bool isvalid(int *arr,int n, int m,int mid){
    int student = 1;
    int total =0, i=0;
    // cout<<mid<<endl;
    while(i<n){
        if(total + arr[i] <= mid){
          total = total+arr[i];
          i++;
        }
        else{
            total = 0;
            student++;
        }
        
        if(student > m){
            return false;
        }
    }
    
    return true;
}

int findPages(int *arr, int n, int m) {
    if(n<m)
      return -1;
    int low = 0;
    int high =0;
    int output=0;
    for(int i=0;i<n;i++){
        high=high+arr[i];
    }
    while(low<=high){
        int mid = low+((high-low)/2);
        // cout<<"low"<<low<<" "<<"mid"<<mid<<" "<<high<<endl;
        if(isvalid(arr,n,m,mid)){
            // cout<<"mid"<<mid<<endl;
            output = mid;
            high  = mid-1;
        }else{
            low = mid+1;
        }
    }


    return output;
}

