#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

// In a NxN chessboard place N queens s.t no two attack each other
// using backtracking approach 
// search for all possible valid configuration positions
// for each queen
// 4x4 with 4 queens = 2 sol
// for 8x8 chessboard with 8 queens = 92 sol

int n;
int ans;
vector<int> queens;
vector<vector<int>> all_sol;

void pr(){
	for(auto v:all_sol){
		for(int i=0; i<v.size(); i++){
			cout<<"("<<i<<","<<v[i]<<") ";
		}
		cout<<endl;
	}
}

bool check(int row, int col){
	for(int prev_row=0; prev_row<row; prev_row++){
		int prev_col=queens[prev_row];
		// condition for queens
		// a) to not be in same row
		// b) and they aren't attacking each other diagonally
		if(col==prev_col || abs(prev_col-col)==abs(prev_row-row)){
			return 0;
		}
	}
	return 1;
}

void rec(int level){ //level=row
	// base case
	if(level==n){
		all_sol.push_back(queens);
		ans++;
		return;
	}
	// choice
	for(int col=0; col<n; col++){
		if(check(level,col)){
			queens.push_back(col);
			rec(level+1);
			queens.pop_back();
		}
	}
}

void solve(){
	cin>>n;
	rec(0);
	cout<<ans<<endl;
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