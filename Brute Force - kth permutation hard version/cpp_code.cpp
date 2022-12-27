#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
using ld=long double;
const int mod=1e9+7; 

int n,k;
vector<int> arr;
vector<int> ans;

void pr(){
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

void permutation(){
	int sz=(int)arr.size();
	int temp=k;
	temp--;
	int fact=1;
	for(int i=1; i<sz; i++){
		fact*=i;
	}
	while(1){
		ans.push_back(arr[temp/fact]);
		arr.erase(arr.begin()+temp/fact);
		if((int)arr.size()==0){
			break;
		}
		temp%=fact;
		fact/=(int)arr.size();
	}
	pr();
}	

void solve(){
	cin>>n>>k;
	if(n<=13){
		for(int i=1; i<=n; i++){
			arr.push_back(i);
		}
	}else{
		for(int i=1; i<n-12; i++){
			cout<<i<<" ";
		}
		for(int i=n-12; i<=n; i++){
			arr.push_back(i);
		}
	}
	permutation();
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