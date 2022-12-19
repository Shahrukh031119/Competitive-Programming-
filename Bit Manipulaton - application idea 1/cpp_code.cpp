#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7; 

// calculate arr[i]^arr[j] for all possible pairs for a given array
// using the fact
// bit expressions are sum independent on each bit

void solve(){
	int n;cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int ans=0;
	// considering signed integer with 32 bit
	// where MSB represents the sign 
	// therefore bit at position 31 is left out
	for(int i=0; i<31; i++){
		int cnt[2]; cnt[0]=cnt[1]=0;
		for(int j=0; j<n; j++){
			cnt[((arr[j]>>i)&1)]++;
		}
		int true_cases=cnt[0]*cnt[1];
		ans += (1LL<<i)*true_cases;
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