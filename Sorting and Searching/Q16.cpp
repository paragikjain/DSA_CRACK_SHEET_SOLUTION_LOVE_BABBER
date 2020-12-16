// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
  
  //Approch: find left side multiplicatoin of a[i] and rifght side and multiply left and right side 
   vector<long long int> product;
   long long int temp=1;
   
   //stroing multiplicaton of all elements which are right side of a[i] excluding a[i]
   for(int i=0;i<n;i++){
       product.push_back(temp);
       temp = temp * nums[i];
   }
   temp =1;
   
   //stroting mutiplicaton of all element which are on left side of a[i] and multipliying with right dode 
   //multiplication
   for(int i=n-1;i>=0;i--){
       product[i] = product[i] *temp;
       temp = temp *nums[i];
   }
   
   return product;
}
