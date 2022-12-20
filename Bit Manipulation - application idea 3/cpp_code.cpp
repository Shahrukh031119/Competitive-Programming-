#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7; 

// to get subsequences of size = x
// consider to choose bitwise & between x elements out of n
// idea is to consider choosing from the largest possible bit as it will 
// outweigh the contributions of all bits lower than that

void solve(){
	int n,x;cin>>n>>x;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int ans=0;
	for(int i=29; i>=0; i--){
		// vector to store nos. having current setbit
		vector<int> bitsetElement;
		for(auto v:arr){
			if(v&(1LL<<i)){
				bitsetElement.push_back(v);
			}
		}
		if(bitsetElement.size()>=x){
			ans+=(1LL<<i);
			arr=bitsetElement;
		}
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