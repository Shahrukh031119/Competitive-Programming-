#include<bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using lli =  int long long;
lli n,n2;
lli tot = 1e9+10;
set<string> gen;

string reverse1(string s , int l ,int r){
    reverse(s.begin()+l,s.begin()+r+1);
    return s;
}


// generates all posible strings from substring reversal with k moves left
void brute(string st , int k){

    if(k==0){ 
        gen.insert(st);
        return;
    }
    int l=0;int r = st.length()-1;

   for(int i=0;i<=r;i++){
        for(int j=i;j<=r;j++){
            string s2 = st;
            s2 = reverse1(st,i,j);
            brute(s2,k-1);
        }   
    }

}


int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    IOS
    lli t;

    cin>>t;
    while(t--){
        string s,t;
        cin >> s >> t;
        set<string> gen1;
        set<string> gen2;

        brute(s,2);
        gen1=gen;      //Stores all possible values of S2 after 2 step substring reversal from S
        gen.clear();

        brute(t,2);
        gen2=gen;       //Stores all possible values of S2 after 2 step substring reversal from T
        gen.clear();

        //Check if any S2 value from the 2 sets are same.
        int c=0;
        for(auto it:gen1){
            if(gen2.find(it)!=gen2.end()){
                cout << "YES" <<"\n";
                c=1;
                break;
            }

        }
        if(!c)
            cout << "NO" << "\n";
    }
    return 0;
}

//TIME COMPLEXITY
// O(N^5 logN)