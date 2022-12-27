#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

char board[8][8];
int ans=0;

vector<int> sol;

bool check(int row, int col){
	for(int i=0; i<row; i++){
		if(sol[i]==col || abs(col-sol[i])==abs(row-i)){
			return 0;
		}
	}
	return 1;
}

void rec(int level){
	if(level==8){ //level
		ans++;
		return;
	}
	for(int col=0; col<8; col++){ //choice
		if(board[level][col]=='.' && check(level,col)){ //check
			// move
			sol.push_back(col);
			rec(level+1);
			sol.pop_back();
		}
	}
}

void solve(){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin>>board[i][j];
		}
	}
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