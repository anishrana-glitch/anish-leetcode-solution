class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i;
        unordered_map<char,int> have;
        unordered_map<char,int> need;

        int n = ransomNote.size();
        int m = magazine.size();

        for(i = 0; i < n; i++){
            need[ransomNote[i]]++;
        }

        for(i = 0; i < m; i++){
            have[magazine[i]]++;
        }

        for(auto i : need){
            char c = i.first;
            int fNeed = i.second;
            int fHave = have[c];

            if(fHave < fNeed)
                return false;
        }

        return true;
    }
};