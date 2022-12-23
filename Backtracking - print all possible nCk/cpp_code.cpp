#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7; 

// from among n elements 
// print all possible subsets with k elements
// used backtracking approach to pick and choose
// elements recursively with the 4 parts framework
// level, choice, check, move

int n,k;
vector<int> arr;
vector<int> sol;

void rec(int level){
	// base case
	if(level==n){
		if(sol.size()==k){
			for(auto v:sol){
				cout<<v<<" ";
			}
			cout<<endl;
		}
		return;
	}

	// choice

	// take
	if(sol.size()<k){
		sol.push_back(arr[level]);
		rec(level+1);
		sol.pop_back();
	}

	// don't take
	rec(level+1);
}

void solve(){
	cin>>n>>k;
	arr.resize(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	rec(0);
	cout<<endl<<endl;
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