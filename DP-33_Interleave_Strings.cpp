// Recursive Method
bool isInterleave(string a, string b, string c){
    if(a.size()==0 && b.size()==0 && c.size()==0)
        return true;
    if(c.size()==0)
        return false;
    bool first=false;
    bool second=false;
    if(a.size()!=0 && a[0]==c[0])
        first=isInterleave(a.substr(1),b,c.substr(1));
    if(b.size()!=0 && b[0]==c[0])
        second=isInterleave(a,b.substr(1),c.substr(1));
    return first | second;
}
// DP Approach
bool isInterleave(string a, string b, string c){
    int m=a.size();
    int n=b.size();
    
    bool dp[m+1][n+1];
    memset(dp,false,sizeof(dp));
    dp[0][0]=true;
    
    for(int i=1;i<=m;i++){
        if(a[i-1]==c[i-1])
            dp[i][0]=dp[i-1][0];
    }
    for(int j=1;j<=n;j++){
        if(b[j-1]==c[j-1])
            dp[0][j]=dp[0][j-1];
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==c[i+j-1] && b[j-1]!=c[i+j-1])
                dp[i][j]=dp[i-1][j];
            else if(a[i-1]!=c[i+j-1] && b[j-1]==c[i+j-1])
                dp[i][j]=dp[i][j-1];
            else if(a[i-1]==c[i+j-1] && b[j-1]==c[i+j-1])
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
        }
    }
    
    return dp[m][n];
}
