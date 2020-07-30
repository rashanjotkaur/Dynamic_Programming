#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[71];
void calculate(){
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=70;i++)
        dp[i]=dp[i-1]+dp[i-2];
}
int main(){
	calculate();
	int t;
	cin>>t;
	while(t--){
	    int w;
	    cin>>w;
	    cout<<dp[w]<<endl;
	}
	return 0;
}
