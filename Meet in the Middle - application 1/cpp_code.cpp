#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// generate all possible subset sums
// for the array with n elements
// and from among them 
// count all with sum<=x

// brute force
// using bitmask approach 
// it takes O(n*2^n) time

// meet in the middle
// divide the whole process into two
// do bitmask
// iterate over one array set 
// and binary search over the other
// it takes O(n*2^n/2) time

vector<int> generate(vector<int> &arr){
	vector<int> subsetsum;
	for(int i=0; i<(1<<arr.size()); i++){
		int sum=0;
		for(int j=0; j<arr.size(); j++){
			if((i>>j)&1){
				sum+=arr[j];
			}
		}
		subsetsum.push_back(sum);
	}
	return subsetsum;
}

void solve(){
	int n,x;cin>>n>>x;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	vector<int> newarr[2];
	for(int i=0; i<n; i++){
		newarr[i&1].push_back(arr[i]);
	}

	vector<int> arr1, arr2;
	arr1=generate(newarr[0]);
	arr2=generate(newarr[1]);

	int ans=0;
	for(int i=0; i<arr1.size(); i++){
		ans+=upper_bound(arr2.begin(),arr2.end(),x-arr1[i])-arr2.begin();
	}
	cout<<ans<<endl;
}

signed main(){
#ifndef ONLINE_JUDGE
	// FOR GETTING INPUT FROM INPUT.TXT
	freopen("input.txt","r",stdin);
	// FOR WRITING OUTPUT TO OUTPUT.TXT
	freopen("output.txt","w",stdout);
#endif	

	IOS
	int _t;cin>>_t;
	// string dummy;getline(cin,dummy);
	while(_t--)
	solve();
}