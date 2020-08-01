#include<bits/stdc++.h>
using namespace std;
void findLCS(vector <vector<int>> dp,string x,string y,
int n,int m,int len,string ans,set <string> &s){
    if(ans.size()==len){
        s.insert(ans);
        return;
    }
    for(int i=n;i>=0;i--){
        for(int j=m;j>=0;j--){
            if(x[i-1]==y[j-1] && dp[i][j]+ans.size()==len) 
                findLCS(dp,x,y,i-1,j-1,len,x[i-1]+ans,s);
        }
    }
}
void LCS(string x,string y,int n,int m){
    vector <vector<int>> dp(n+1,vector <int> (m+1));
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int j=0;j<=m;j++)
        dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int len=dp[n][m];
    string res;
    set <string> s;
    findLCS(dp,x,y,n,m,len,res,s);
    for(auto it=s.begin();it!=s.end();it++)
        cout<<(*it)<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    LCS(a,b,a.size(),b.size());
	    cout<<endl;
	}
	return 0;
}
