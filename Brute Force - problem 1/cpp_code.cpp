#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7; 

// Given n, find all possible combination of nos for the set abcdefghij
// s.t a-j belongs to {0,1,2,3,4,5,6,7,8,9}
// and it satisfies the condition 
// abcde/fghij = n
// where n belongs to [1,99]
// and a-j is a set of all distinct integers


//using brute force
// possible approaches
// solve2 is more optimal than solve1
// as less nos are generated

int n;

// generate solutions using different possible permutations 
// for the set {0,1,2,3,4,5,6,7,8,9}
void solve1(){
	vector<int> arr={0,1,2,3,4,5,6,7,8,9};
	do{
		int abcde=arr[0]*10000 + arr[1]*1000 + arr[2]*100 + arr[3]*10 + arr[4];
		int fghij=arr[0+5]*10000 + arr[1+5]*1000 + arr[2+5]*100 + arr[3+5]*10 + arr[4+5];
		if(abcde%fghij==0){
			if(abcde/fghij==n){
				cout<<abcde<<" "<<fghij<<endl;
			}
		}
	}while(next_permutation(arr.begin(),arr.end()));
}

// generate solutions using the fact that fghij belongs to [1,99999]
// s.t abcde = n*fghij
// valid solution iff abcdefghij are all distinct
void solve2(){
	for(int fghij=1234; fghij<=98765/n; fghij++){
		int abcde=n*fghij;

		set<int> s;
		int temp=abcde;
		for(int i=0; i<5; i++){
			s.insert(temp%10);
			temp/=10;
		}

		temp=fghij;
		for(int i=0; i<5; i++){
			s.insert(temp%10);
			temp/=10;
		}

		if(s.size()==10){
			cout<<abcde<<" "<<fghij<<endl;
		}
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
	cin>>n;
	solve1();
	cout<<endl<<endl;
	solve2();
}