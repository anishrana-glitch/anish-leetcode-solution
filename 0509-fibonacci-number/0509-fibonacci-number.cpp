class Solution {
public:
unordered_map<int,int> dp;
    int fib(int n) {
       if (n==0)
       return 0;
       if (n==1)
       return 1;
       if(dp.find(n)!= dp.end())
       return dp[n];
       int a1= fib(n-1);
       int a2=fib(n-2);
       dp[n]=a1+a2;
       return a1+a2;
    }
};
