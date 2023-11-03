// we have to count total number of dearrangements such that none of the number is at original position

// eg-> n=3 i.e. {0,1,2}
// possible dearrangement are {1,2,0}, {2,0,1}
using namespace std;

// using recursion
#define MOD 1000000007

long long int countDerangements(int n) {
    // Write your code here.
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    int ans=(((n-1)%MOD)*((countDerangements(n-2))%MOD+(countDerangements(n-1)%MOD)))%MOD;
    return ans;
}


// using recursion + memoization
#include<vector>

long long int solveMem(int n,vector<long long int>&dp)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=(n-1)*(solveMem(n-2,dp)+solveMem(n-1,dp));
    
    return dp[n];
}
long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int>dp(n+1,-1);
    long long int ans=solveMem(n,dp);
    return ans;
}

// using tabulation
long long int solveTab(int n)
{
    vector<long long int>dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        long long int first=dp[i-1]%MOD;
        long long int second=dp[i-2]%MOD;
        long long int sum=(first+second)%MOD;
        long long int ans=((i-1)*sum)%MOD;
        dp[i]=ans;
    }
    return dp[n];
}
long long int countDerangements(int n) {
    // Write your code here.
    long long int ans=solveTab(n);
    return ans;
}


// space optimization
#define MOD 1000000007
#include<vector>

long long int solveTab(int n)
{
    long long int prev2=0;
    long long int prev1=1;
    for(int i=3;i<=n;i++)
    {
        long long int sum=(prev2+prev1)%MOD;
        long long int ans=((i-1)*sum)%MOD;
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
long long int countDerangements(int n) {
    // Write your code here.
    long long int ans=solveTab(n);
    return ans;
}