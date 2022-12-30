#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// 4sum
// 4 variants

// variant 1
// check if arr[a]+arr[b]+arr[c]+arr[d]=target
// where a,b,c,d belongs to [0,n-1]
// is possible or not
// a,b,c,d can be same

// variant 2
// find for the case when 
// a<b<c<d

// variant 3
// find one such instance 
// and print the values of a,b,c,d

// variant 4
// count all such instances
// and give total count

bool is4SUMpossible(int n, int x, vector<int> &arr){
	map<int,int> mp;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			mp[arr[i]+arr[j]]=1;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(mp[x-(arr[i]+arr[j])]){
				return 1;
			}
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
	if(is4SUMpossible(n,x,arr)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
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