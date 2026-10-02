class Solution { 
public: 
    int findTargetSumWays(vector<int>& nums, int target) { 
        int total_sum=0; 
        int n= nums.size(); 
        int i,j; 
        
        for(i=0;i<n;i++){ 
            total_sum=total_sum+nums[i]; 
        } 
        
        int sum=0; 
        sum=(total_sum+target)/2; 
        
        if (abs(target) > total_sum || (total_sum + target) % 2 != 0) 
            return 0; 
         
        vector<vector<int>> dp(n+1); 
        
        for(i=0;i<=n;i++) 
        { 
            vector<int> t(sum+1,0); 
            dp[i]=t; 
        } 
        
        for(j=0;j<=sum;j++) 
            dp[n][j]=0; 
 
        dp[n][0]=1; 
        
        for(i=n-1;i>=0;i--) 
        { 
            for(j=0;j<=sum;j++) 
            { 
                if(nums[i]>j) 
                    dp[i][j]=dp[i+1][j]; 
                else 
                    dp[i][j]=(dp[i+1][j-nums[i]])+(dp[i+1][j]); 
            } 
        } 
        
        return dp[0][sum]; 
    } 
};