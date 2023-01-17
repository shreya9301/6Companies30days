//DAY-3 : LeetCode Problem Number 299

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0,cows = 0;
        map<int,int> secret_freq,guess_freq;   
        string ans = "";

        for(int i = 0; i < guess.size() ;i++){
            if(secret[i] == guess[i]){
                bulls++;
            }else{
                secret_freq[secret[i] - '0']++;
                guess_freq[guess[i] - '0']++;
            }

        }
        for(auto g: guess_freq){
            if(secret_freq.find(g.first) != secret_freq.end()){
                cows += min(g.second,secret_freq[g.first]);
            }
        }
        ans += to_string(bulls);
        ans += "A";
        ans += to_string(cows);
        ans += "B";
        return ans;
    }
};
