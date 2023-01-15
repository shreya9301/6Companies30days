//DAY-2 : LeetCode Problem Number 216

class Solution {
public:

    void validCombination(int k, int n, vector<int> &combination, vector<vector<int>> &res,int start){
        if(n == 0 and k == 0){
            res.push_back(combination);
        }
        if(n == 0) return;
        if(k == 0) return;

        for(int i = start;i <= 9;i++){
            combination.push_back(i);
            validCombination(k - 1,n - i,combination,res,i + 1);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        //unique combinations to be displayed
        //no number to be repeated in a combination
        //numbers range - [1,9]
        //max nums to be used - k
        //problem based on backtracking
        vector<vector<int>> res;
        vector<int> combination;
        validCombination(k,n,combination,res,1);
        return res;

    }
};
