//DAY - 4 : LeetCode problem number 368
class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() ,a = -1 ,  lastIndex =-1;
        vector<int> dp(n, 1);
        vector<int> ans(n, -1);
        sort(nums.begin() , nums.end());

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){

                if((nums[i]%nums[j] == 0) && dp[j] >= dp[i]){ 
                    dp[i] = dp[j] + 1;   
                    ans[i] = j;
                }             
            }
            if(dp[i] > a){
                a = dp[i];  
                lastIndex = i;
            } 
        }

        vector<int>path;
        while(lastIndex != -1){
            path.push_back(nums[lastIndex]);
            lastIndex = ans[lastIndex];
        }
        reverse(path.begin(), path.end());       
        return path;
    }
};

