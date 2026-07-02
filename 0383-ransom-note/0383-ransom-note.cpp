class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i;
        unordered_map<char,int> r;
        unordered_map<char,int> z;
        int n=ransomNote.size();
        int m=magazine.size();
        for(i=0;i<n;i++){
            r[ransomNote[i]]++;
        }
        for(i=0;i<m;i++){
            z[magazine[i]]++;
        }
        for(i = 0; i < n; i++) {
            if(r[ransomNote[i]] > z[ransomNote[i]])
            return false;
        }
        return true;

    }
};