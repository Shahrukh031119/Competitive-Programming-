#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

vector<vector<int>> all_sol;
vector<int> curr_sol;
int n,k;
map<int,int> mp;

void pr(){
	for(int i=0; i<all_sol[k-1].size(); i++){
		cout<<all_sol[k-1][i]<<" ";
	}
	cout<<endl;
}

void rec(int level){
	// base case
	if(level>n){
		all_sol.push_back(curr_sol);
		return;
	}
	for(auto i:mp){
		if(i.second==0) continue;
		curr_sol.push_back(i.first);
		mp[i.first]--;
		rec(level+1);
		curr_sol.pop_back();
		mp[i.first]++;
	}
}

void solve(){
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		mp[i]=1;
	}
	rec(1);
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