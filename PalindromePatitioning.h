class Solution {
public:
    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i <= j){
            if(s[i++] != s[j--])return false;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pre, rlt;
        if(s.size() == 0){
            vector<string> t;
            rlt.push_back(t);            
            return rlt;
        }
        if(s.size() == 1){
            vector<string> t(1,s);
            rlt.push_back(t);
            return rlt;
        }
        for(int i = 1; i <= s.size(); i++){
            if(isPalindrome(s.substr(0,i))){
                pre = partition(s.substr(i));
                for(int j = 0; j < pre.size(); j++){
                    pre[j].insert(pre[j].begin(), s.substr(0,i));
                    rlt.push_back(pre[j]);
                }
            }
        }
        return rlt;
    }
};
