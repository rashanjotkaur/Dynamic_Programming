#include<bits/stdc++.h>
using namespace std;
int LCS(string x,string y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int j=0;j<=m;j++)
        dp[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    return dp[n][m];
}
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string x,y;
	    cin>>x>>y;
	    cout<<LCS(x,y,n,m)<<endl;
	}
	return 0;
}
