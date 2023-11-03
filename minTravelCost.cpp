/*
You are given a DAYS array consisting of  ‘N’ days when Ninjas will be traveling during the year. 
Each Day is an integer between 1 to 365 (both inclusive)


Train tickets are sold in three different ways:

A 1-day pass is sold for 'COST'[0] coins, and
A 7-day pass is sold for 'COST'[1] coins, and
A 30-day pass is sold for 'COST'[2] coins, and

*/





// using recursion 
#include<iostream>
using namespace std;
int solve(int n,vector<int>&days,vector<int>&cost,int index)
{
    // base case
    if(index>=n)
        return 0;

    // pass for 1 day
    int option1=cost[0]+solve(n,days,cost,index+1);

    // pass for 7 day
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int option2=cost[1]+solve(n, days, cost, i);

    // pass for 30 days
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solve(n, days, cost, i);

    return min(option1,min(option2,option3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n,days,cost,0);
}




// recursion + memoization
int solve(int n,vector<int>&days,vector<int>&cost,int index,vector<int>&dp)
{
    // base case
    if(index>=n)
        return 0;


    if(dp[index]!=-1)
        return dp[index];
    // pass for 1 day
    int option1=cost[0]+solve(n,days,cost,index+1,dp);

    // pass for 7 day
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int option2=cost[1]+solve(n, days, cost, i,dp);

    // pass for 30 days
    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solve(n, days, cost, i,dp);

    dp[index]= min(option1,min(option2,option3));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int>dp(n+1,-1);
    return solve(n,days,cost,0,dp);
}





// using tabulation
int solveTab(int n,vector<int>&days,vector<int>&cost)
{
    vector<int>dp(n+1,INT_MAX);
    dp[n]=0;

    for(int k=n-1;k>=0;k--)
    {
    // pass for 1 day
    int option1=cost[0]+dp[k+1];
    
    // pass for 7 day
    int i;
    for(i=k;i<n && days[i]<days[k]+7;i++);
    int option2=cost[1]+dp[i];

    // pass for 30 days
    for(i=k;i<n && days[i]<days[k]+30;i++);
    int option3=cost[2]+dp[i];

    dp[k]= min(option1,min(option2,option3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solveTab(n,days,cost);
}





// space optimization 
#include<queue>
int solveTab(int n,vector<int>&days,vector<int>&cost)
{
    int ans=0;
    queue<pair<int,int>>weekly;
    queue<pair<int,int>>monthly;
    for(int day:days)
    {
        // step1:- remove expired days from queue
        while(!monthly.empty() && monthly.front().first + 30<=day)
            monthly.pop();
        while(!weekly.empty() && weekly.front().first + 7<=day)
            weekly.pop();

        // step2:- push the current day and its cost in the queue
        weekly.push(make_pair(day,ans+cost[1]));
        monthly.push(make_pair(day,ans+cost[2]));

        // step3:- update the ans
        ans=min(ans+cost[0],min(monthly.front().second,weekly.front().second));
        
    }
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solveTab(n,days,cost);
}