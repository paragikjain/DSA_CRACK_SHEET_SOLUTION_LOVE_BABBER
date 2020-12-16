#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	  cin>>a[i];
	int round;
	cin>>round;
    while(round--){
		int power;
		cin>>power;
		int count=0;
		int total=0;

		for(int i=0;i<n;i++){
			if(a[i]<=power){
				total=total+a[i];
				count++;
			}
		}
		cout<<count<<" "<<total<<endl;
	}


}