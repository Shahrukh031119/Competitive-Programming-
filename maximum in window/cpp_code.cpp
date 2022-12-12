#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7;

void solve(){
	int n,k;cin>>n>>k;
	multiset<int> ms;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	for(int i=0; i<n; i++){
		ms.insert(v[i]);
		if(ms.size()==k){
			cout<<*ms.rbegin()<<" ";
			ms.erase(ms.find(v[i-k+1]));
		}
	}
	cout<<endl;
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