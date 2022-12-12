#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7;

int distinct=0;
int freq[1000100];

void solve(){
	int n,m;cin>>n>>m;
	map<int,int> mp;
	for(int i=0; i<n; i++){
		int x,u;cin>>x>>u;
		mp[x*u]++;
	}
	int ans=0;
	for(int i=0; i<m; i++){
		int y,v;cin>>y>>v;
		if(mp[y*v]){
			ans++;
			mp[y*v]--;
		}
		if(mp[y*v]==0){
			mp.erase(y*v);
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