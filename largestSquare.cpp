

#include <iostream>
using namespace std;


// using recursion top down approach ({0,0}-->{n-1,m-1})

class Solution{
    int solve(vector<vector<int>>&mat,int n,int m,int &maxi)
    {
        if(n>=mat.size() || m>=mat[0].size())
            return 0;
            
        int right=solve(mat,n,m+1,maxi);
        int diagonal=solve(mat,n+1,m+1,maxi);
        int down=solve(mat,n+1,m,maxi);
        
        if(mat[n][m]==1)
        {
           int ans=1+min(right,min(diagonal,down));
           maxi=max(ans,maxi);
           return ans;
        }
        else
        {
            return 0;
        }
    }
public:
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
        solve(mat,0,0,maxi);
        return maxi;
    }
};







// recursion + memoization
class Solution{
    int solve(vector<vector<int>>&mat,int i,int j,int &maxi,vector<vector<int>>&dp)
    {
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        int right=solve(mat,i,j+1,maxi,dp);
        int diagonal=solve(mat,i+1,j+1,maxi,dp);
        int down=solve(mat,i+1,j,maxi,dp);
        
        if(mat[i][j]==1)
        {
           dp[i][j]=1+min(right,min(diagonal,down));
           maxi=max(dp[i][j],maxi);
           return dp[i][j];
        }
        else
        {
            return dp[i][j]=0;
        }
    }
public:
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(mat,0,0,maxi,dp);
        return maxi;
    }
};






// using tabulation
class Solution{
    void solveTab(vector<vector<int>>&mat,int &maxi)
    {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>dp(row+1,vector<int>(col+1,0));
        // base case
        // already set to zero
        
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                int right=dp[i][j+1];
                int diagonal=dp[i+1][j+1];
                int down=dp[i+1][j];
        
                if(mat[i][j]==1)
                {
                   dp[i][j]=1+min(right,min(diagonal,down));
                   maxi=max(dp[i][j],maxi);
                }
                else
                {
                    dp[i][j]=0;
                } 
            }
        }
    }
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
        solveTab(mat,maxi);
        return maxi;
    }
};







// space optimization    SC= O(M)
class Solution{

    void solveTab(vector<vector<int>>&mat,int &maxi)
    {
        int row=mat.size();
        int col=mat[0].size();
        vector<int>curr(col+1,0);
        vector<int>next(col+1,0);
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                int right=curr[j+1];
                int diagonal=next[j+1];
                int down=next[j];
        
                if(mat[i][j]==1)
                {
                   curr[j]=1+min(right,min(diagonal,down));
                   maxi=max(curr[j],maxi);
                }
                else
                {
                    curr[j]=0;
                } 
            }
            next=curr;//upar jaa rahe hai isiliye ulta hoga
        }
    }
public:
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
       
        solveTab(mat,maxi);
        return maxi;
    }
};






// more space optimization     SC = O(1)

// instead of storing the value in additional dp array we are storing the value in the same array in this way no extra space is used
// but the maximum value is stored in the maxi variable as the answer is not stored in mat[0][0]
class Solution{

    void solveSO(vector<vector<int>>&mat,int &maxi)
    {
        int row=mat.size();
        int col=mat[0].size();
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                int right= (j==col-1) ? 0 : mat[i][j+1];
                int diagonal= (i==row-1 || j==col-1) ? 0 : mat[i+1][j+1];
                int down= (i==row-1) ? 0 : mat[i+1][j];
        
                if(mat[i][j]==1)
                {
                   mat[i][j]=1+min(right,min(diagonal,down));
                   maxi=max(mat[i][j],maxi);
                }
                else
                {
                    mat[i][j]=0;
                } 
            }
        }
    }
    
public:
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int maxi=0;
       
        solveSO(mat,maxi);
        return maxi;
    }
};