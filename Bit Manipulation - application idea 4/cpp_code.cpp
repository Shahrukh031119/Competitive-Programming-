#include<bits/stdc++.h>
using namespace std;

// #define for(i,start,stop) for(int i=start, i<=stop; i++)
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back

using ld=long double;

const int mod=1e9+7; 

// since l-r query problem 
// therefore better to maintain a prefix sum
// here prefix sum keep a count of number of setbits for each number
// to maximise xor , count 1's and 0's and assign x1's corresponding min of that count
// similarly look for different idea to maximise bitwise & and bitwise |

int prefixSum[1000001][31];

void solve(){
	int n;cin>>n;
	vector<int> arr(n);
	// initialise prefixsum array to 0 for all the bits of each number
	for(int i=0; i<=n; i++){
		for(int j=0; j<31; j++){
			prefixSum[i][j]=0;
		}
	}
	// for each number check & update which bit is set
	for(int i=1; i<=n; i++){
		int num;cin>>num;
		int bitpos=0;
		while(num>0){
			prefixSum[i][bitpos]=num%2;
			bitpos++;
			num/=2;
		}
	}
	// create prefix sum for each number
	for(int i=1; i<=n; i++){
		for(int j=0; j<31; j++){
			prefixSum[i][j]+=prefixSum[i-1][j];
		}
	}
	//  handle q queries
	int q;cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		double totalSize=(r-l+1.0)/2;
		int ans=0;
		int x1=0, x2=0, x3=0;
		for(int j=0; j<31; j++){
			int setbits=prefixSum[r][j]-prefixSum[l-1][j];
			if(setbits<totalSize){
				x1+=(1LL<<j);
			}
			if(setbits!=(r-l+1)){
				x2+=(1LL<<j);
			}
			if(setbits){
				x3+=(1LL<<j);
			}
		}
		ans=x1+x2+x3;
		cout<<ans<<endl;
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
	int _t;cin>>_t;
	// string dummy;getline(cin,dummy);
	while(_t--)
	solve();
}