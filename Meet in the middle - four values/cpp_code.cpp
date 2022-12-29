#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

bool is4SUMpossible(int n, int x, vector<int> &arr){
	map<int,int> mp;
	for(int b=n-2; b>=1; b--){
		for(int a=b-1; a>=0; a--){
			if(mp[x-arr[a]-arr[b]]){
				return 1;
			}
		}
		int c=b;
		for(int d=c+1; d<n; d++){
			mp[arr[c]+arr[d]]=1;
		}
	}
	return 0;
}

void solve(){
	int n,x;cin>>n>>x;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	bool ans=is4SUMpossible(n,x,arr);
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO";
	}
}

signed main(){
#ifndef ONLINE_JUDGE
	// FOR GETTING INPUT FROM INPUT.TXT
	freopen("input.txt","r",stdin);
	// FOR WRITING OUTPUT TO OUTPUT.TXT
	freopen("output.txt","w",stdout);
#endif	

	IOS
	// int _t;cin>>_t;
	// string dummy;getline(cin,dummy);
	// while(_t--)
	solve();
}