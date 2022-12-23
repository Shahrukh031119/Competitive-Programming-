#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7; 

// using freq map to keep count of element occurence at every instance
// solved using backtracking/recursion approach

int n;
vector<vector<int>> all_sol;
map<int,int> mp;
vector<int> curr_per;

void pr(){
	for(auto v:all_sol){
		for(auto ele:v){
			cout<<ele<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

void rec(int level){
	// base case
	if(level==n){
		all_sol.push_back(curr_per);
		return;
	}
	// choice
	for(auto i:mp){
		if(i.second==0) continue;
		curr_per.push_back(i.first);
		mp[i.first]--;
		rec(level+1);
		curr_per.pop_back();
		mp[i.first]++;
	}
}

void solve(){
	cin>>n;
	for(int i=0; i<n; i++){
		int x;cin>>x;
		mp[x]++;
	}
	rec(0);
	pr();

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