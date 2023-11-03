// there are total of n fences and k colours and you have to paint the fences 
// such that not more than two consecutive fences should have same color


#define MOD 1000000007
#include <iostream>
using namespace std;


// using recursion
int sum(int a,int b)
{
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a,int b)
{
    return ((a%MOD) * (b%MOD))%MOD;
}

int solve(int n,int k)
{
    if(n==1)
        return k;
    if(n==2)
        return sum(k,mul(k,k-1));

    int ans=sum(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}
int numberOfWays(int n, int k) 
{
    // Write your code here	
    return solve(n,k);
}





// recursion + memoization

int sum(int a,int b)
{
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a,int b)
{
    return ((a%MOD)*1LL * (b%MOD))%MOD;// 1LL is long long integer to store the larger numbers
}

int solve(int n,int k,vector<int>&dp)
{
    if(n==1)
        return k;
    if(n==2)
        return sum(k,mul(k,k-1));

    if(dp[n]!=-1)
        return dp[n];
    int same=solve(n-2,k,dp);
    int diff=solve(n-1,k,dp);
    dp[n]=sum(mul(same,k-1),mul(diff,k-1));
    return dp[n];
}
int numberOfWays(int n, int k) 
{
    // Write your code here	
    vector<int>dp(n+1,-1);
    return solve(n,k,dp);
}







// using tabulation or bottom donw approach
int sum(int a,int b)
{
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a,int b)
{
    return ((a%MOD)*1LL * (b%MOD))%MOD;
}

int solve(int n,int k)
{

    int prev2=k;//iske result ke last me same colours wale 2 colours add honge 
    int prev1=sum(k,mul(k,k-1));//iske result ke last me different colors wale 1 color add honge

    for(int i=3;i<=n;i++)
    {
        int total=sum(mul(prev2,k-1),mul(prev1,k-1));
        prev2=prev1;
        prev1=total;
    }
    return prev1;
}
int numberOfWays(int n, int k) 
{
    // Write your code here	
    return solve(n,k);


}
