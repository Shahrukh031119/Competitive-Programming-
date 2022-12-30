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

vector<int> is4SUMpossible(int n, int x, vector<int> &arr){
	map<int,pair<int,int>> mp;
	vector<int> ans;
	for(int b=n-2; b>=1; b--){
		for(int a=b-1; a>=0; a--){
			if(mp.find(x-arr[a]-arr[b])!=mp.end()){
				pair<int,int> idx=mp[x-arr[a]-arr[b]];
				return ans={a,b,idx.first,idx.second};
			}
		}
		int c=b;
		for(int d=c+1; d<n; d++){
			mp[arr[c]+arr[d]]={c,d};
		}
	}
	return ans;
}

void solve(){
	int n,x;cin>>n>>x;
	vector<int> arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	vector<int> ans=is4SUMpossible(n,x,arr);
	if(ans.size()!=0){
		for(auto v:ans){
			cout<<v<<" ";
		}
		cout<<endl;
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