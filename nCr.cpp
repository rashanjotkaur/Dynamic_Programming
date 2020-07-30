#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;
ll nCr[1000+1][800+1];
void calculate(){
    memset(nCr,0,sizeof(nCr));
    for(int n=0;n<=1000;n++){
        for(int r=0;r<=800;r++){
            if(r>n)
                continue;
            if(r==0 || n==r)
                nCr[n][r]=1;
            else if(r>n/2)
                nCr[n][r]=nCr[n][n-r];
            else
                nCr[n][r]=(nCr[n-1][r]+nCr[n-1][r-1])%mod;
        }
    }
}
int main(){
    calculate();
	int t;
	cin>>t;
	while(t--){
	    int n,r;
	    cin>>n>>r;
	    ll ans=nCr[n][r];
	    cout<<ans<<endl;
	}
	return 0;
}
