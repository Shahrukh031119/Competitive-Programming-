#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

int n;
vector<int> s_queens;
int ans=0;

bool check(int row, int col){
	for(int prow=0; prow<row; prow++){
		int pcol=s_queens[prow];
		if(col==pcol){
			return 0;
		}else if(abs(prow-row)==abs(pcol-col)){
			return 0;
		}else if((abs(prow-row)==1 && abs(pcol-col)==2) || (abs(prow-row)==2 && abs(pcol-col)==1)){
			return 0;
		}
	}
	return 1;
}

void rec(int level){
	// base case
	if(level==n){
		ans++;
		return;
	}
	// choice
	for(int col=0; col<n; col++){
		if(check(level,col)){
			s_queens.push_back(col);
			rec(level+1);
			s_queens.pop_back();
		}
	}
}

void solve(){
	cin>>n;
	rec(0);
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
	// int _t;cin>>_t;
	// string dummy;getline(cin,dummy);
	// while(_t--)
	solve();
}