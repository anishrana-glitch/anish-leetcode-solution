class Solution {
public:
    long long fun(vector<int> &a, int n, int speed)
    {
        long long h=0;
        for (int i=0; i<n;i++)
        {
            h += a[i]/speed;
            if(a[i]%speed!=0)
                h++;
        }
        return h;
    }
    int minEatingSpeed(vector<int> &a, int guard)
    {
        int n=a.size();
        int low=1;
        int high=*max_element(a.begin(), a.end());
        int res=-1;
        while(low<=high)
        {
            int guess=low+(high-low)/2;
            long long hour=fun(a,n,guess);
            if (hour>guard)
            {
                low=guess+1;
            }
            else
            {
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};