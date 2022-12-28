#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// to generate all possible subsets
// from a given array of n elements

// solution
// using bit mask to consider all possible
// 2^n subsets 

int n;
vector<vector<int>> all_sol;
vector<int> arr;

void pr(){
	for(auto subset:all_sol){
		cout<<"{ ";
		for(auto v:subset){
			cout<<v<<" ";
		}
		cout<<"}"<<endl;
	}
}

void solve(){
	cin>>n;
	arr.resize(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int mask=0; mask<(1<<n); mask++){
		vector<int> subset;
		for(int i=0; i<n; i++){
			if((mask>>i)&1){
				subset.push_back(arr[i]);
			}
		}
		all_sol.push_back(subset);
	}
	pr();
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