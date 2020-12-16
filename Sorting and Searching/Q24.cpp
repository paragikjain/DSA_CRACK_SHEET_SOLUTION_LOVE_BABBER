#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool isvaild(ll arr[],ll mid,ll n,ll cow){
	ll i=1;
	ll c =1;
	ll total = 0;
	while(i<n){
	  total = total+ (arr[i]-arr[i-1]);
	  if(total >=mid){
	  	c++;
	  	total = 0;
	  }
	  i++;
	}
	if(c<cow){
		return false;
	}
	else{
		return true;
	}
}
int main() {
	// ll testcase;
	// cin>>testcase;
	// while(testcase--){
	ll n,cow;
	cin>>n>>cow;
	ll a[n];
	ll out;
	for(ll i=0;i<n;i++){
	  cin>>a[i];	
	}
	sort(a,a+n);
	ll low = a[0];
	ll high = a[n-1];
	while(low<=high){
		ll mid = low +((high-low)/2);
    // cout<<mid<<endl;
		if(isvaild(a,mid,n,cow)){
			out = mid;
			low = mid +1;
		}
		else{
			high = mid-1;
		}
	}
	
	cout<<out<<endl;
// }


	return 0;
}