class Solution {
public:
    string removeDuplicates(string s) {
       int n= s.size();
       stack <char> st;
       int i;
       string res;
       for(i=0;i<n;i++)
       {
        if(!st.empty() and st.top()==s[i])
        {
            st.pop();
            continue;
        }
        else
        st.push(s[i]);
       }
       while(!st.empty())
       {
        res.push_back(st.top());
        st.pop();
       } 
       reverse(res.begin(),res.end());
       return res;
    }
};