//lintcode 1208
class Solution {
public:
    /**
     * @param nums: the given array
     * @param s: the given target
     * @return: the number of ways to assign symbols to make sum of integers equal to target S
     */
    void dfs(vector<int> &nums,int id,int s,int local,int& res){
        if(id == nums.size()){
            if(local == s){
                res++;
            }
            return;
        }
        int val = nums[id];
        dfs(nums,id+1,s,local-nums[id],res);
        dfs(nums,id+1,s,local+nums[id],res);
    }
    int findTargetSumWays(vector<int> &nums, int target) {
        // Write your code here
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        int diff = sum - target;
        // can't be smaller
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        // target + diff - diff = target
        int n = nums.size(), sub = diff / 2;
        vector<vector<int>> dp(n + 1, vector<int>(sub + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i-1];
            for (int j = 0;j <= sub;j++){
                dp[i][j] = dp[i-1][j];
                if(j - num >= 0){
                    dp[i][j] += dp[i-1][j-num];
                }
            }
        }
        return dp[n][sub];
    }
};