#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7; 

// imp property of nos interms of bits
// a+b = (a&b) + (a|b)
// so a+b is constant
// to make a*a + b*b maximum with constant sum
// make larger no. as large as possible by shifting bits using a|b
// and making smaller no. as small as possible by shifting bits using a&b

void solve(){
	int n;cin>>n;
	int arr[n];
	// array to store count of 1's across all bits for each number
	int cnt[21];
	memset(cnt,0,sizeof(cnt));
	for(int i=0; i<n; i++){
		cin>>arr[i];
		for(int j=0; j<21; j++){
			cnt[j]+=((arr[i]>>j)&1);
		}
	}
	int ans=0;
	for(int i=0; i<n; i++){
		int largestnum=0;
		for(int j=0; j<21; j++){
			if(cnt[j]){
				largestnum|=(1LL<<j);
				cnt[j]--;
			}
		}
		ans+=largestnum*largestnum;
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