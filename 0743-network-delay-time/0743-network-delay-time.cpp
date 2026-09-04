class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> a(n);

        for(int i = 0; i < times.size(); i++)
        {
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];

            a[s-1].push_back({d-1, w});
        }

        vector<int> res(n, INT_MAX);
        vector<int> vis(n, 0);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> q;

        q.push({0, k-1});
        res[k-1] = 0;

        while(!q.empty())
        {
            pair<int,int> p = q.top();
            q.pop();

            int dis = p.first;
            int node = p.second;

            if(vis[node] == 1)
                continue;

            vis[node] = 1;

            for(int j = 0; j < a[node].size(); j++)
            {
                int neigh = a[node][j].first;
                int w = a[node][j].second;

                if(res[neigh] > dis + w)
                {
                    res[neigh] = dis + w;
                    q.push({res[neigh], neigh});
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(res[i] == INT_MAX)
                return -1;

            ans = max(ans, res[i]);
        }

        return ans;
    }
};