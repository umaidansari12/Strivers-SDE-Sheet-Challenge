#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices) {
    // Write your code here.
    // Buy first and then sell and meanwhile find maximum profit, trying every buying and selling combination
    // TC - O(N*N)
    // SC - O(1)
    int maximum_profit = 0, n = prices.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            maximum_profit = max(maximum_profit, prices[j] - prices[i]);
        }
    }
    return maximum_profit;
}

int maximumProfit(vector<int> &prices) {
    // Write your code here.
    // Buy the stocks at the minimum price and sell at maximum prices
    // TC - O(N)
    // SC - O(N)
    int n = prices.size(), min_stock_price = INT_MAX, maximum_profit = 0;
    for (int i = 0; i < n; i++) {
        min_stock_price = min(min_stock_price, prices[i]);
        maximum_profit = max(maximum_profit, prices[i] - min_stock_price);
    }
    return maximum_profit;
}