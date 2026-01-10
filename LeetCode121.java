class Solution {
    public int maxProfit(int[] prices) {
        int maxprof = 0;
        int b = 0;
        for (int s = 1; s < prices.length; s++) {
            if (prices[s] > prices[b]) {
                int profit = prices[s] - prices[b];
                maxprof = Math.max(profit, maxprof);
            }
            else {
                b = s;
            }
        }
        return maxprof;
    }
}
