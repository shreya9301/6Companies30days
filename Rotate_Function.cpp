//DAY-3 : LeetCode Problem Number 396

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }

        int max_ans = 0,sum = 0;
        for(int i= 0;i<n;i++){
            max_ans += (nums[i] * i);//precomputed rotation sum
            sum += nums[i];
        }
        int kth_ans = max_ans;
        int index = n - 1;
        for(int k = 1;k <= n - 1;k++){ //for k rotations
            kth_ans = kth_ans - ((n - 1)*nums[index]) + (sum - nums[index]);
            index--;
            max_ans = max(max_ans,kth_ans);
        }
        return max_ans;
    }
};
