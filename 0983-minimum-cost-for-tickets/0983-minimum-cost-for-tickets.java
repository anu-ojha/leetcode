
class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int n = days[days.length - 1];
        boolean[] willTravel = new boolean[n + 1];
        int[] dp = new int[n + 1];
        for (int day : days) {
            willTravel[day] = true;
        }
        dp[0] = 0;	// Initialize the dp array (Could be skip)

        for (int i = 1; i < dp.length; i++) {
            if (willTravel[i]) {
                dp[i] = dp[i - 1] + costs[0];
                dp[i] = Math.min(dp[i], dp[Math.max(0, i - 7)] + costs[1]);
                dp[i] = Math.min(dp[i], dp[Math.max(0, i - 30)] + costs[2]);
            } else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[n];
    }
}