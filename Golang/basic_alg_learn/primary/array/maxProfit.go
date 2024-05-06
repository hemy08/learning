package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2zsx1/
*/
func maxProfit(prices []int) int {
	begin := 0
	end := 0
	profit := 0

	for index := 1; index < len(prices); index++ {
		if prices[index] > prices[end] {
			end = index
			continue
		}

		profit = profit + prices[end] - prices[begin]
		begin = index
		end = index
	}

	profit = profit + prices[end] - prices[begin]
	return profit
}

func maxProfitOptimization(prices []int) int {
	begin := 0
	end := 0
	profit := 0

	for index, v := range prices {
		if v <= prices[end] {
			profit = profit + prices[end] - prices[begin]
			begin = index
		}

		end = index
	}

	profit = profit + prices[end] - prices[begin]
	return profit
}

func maxInt(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func maxProfitDP(prices []int) int {
	nums := len(prices)
	dp := make([][2]int, nums)

	dp[0][0] = 0
	dp[0][1] = -prices[0]

	for i := 1; i < nums; i++ {
		// 当天手中没有股票 = max（前一天没有股票， 前一天有股票但以今天的价格出售）
		dp[i][0] = maxInt(dp[i-1][0], dp[i-1][1]+prices[i])
		// 当天手中有股票 = max（前一天有股票， 前一天有股票但以今天的价格买入）
		dp[i][1] = maxInt(dp[i-1][1], dp[i-1][0]-prices[i])
	}

	return dp[nums-1][0]
}

func maxProfitDP2(prices []int) int {
	nums := len(prices)

	// 利润，假设前一天手中没有股票
	lastHave := 0 - prices[0]
	lastNoHave := 0

	for i := 1; i < nums; i++ {
		// 当天手中没有股票 = max（前一天没有股票今天不买入， 前一天有股票但以今天的价格出售）
		curNoHave := maxInt(lastNoHave, lastHave+prices[i])
		// 当天手中有股票 = max（前一天有股票今天不出售， 前一天没有股票但以今天的价格买入）
		curHave := maxInt(lastHave, lastNoHave-prices[i])
		lastHave = curHave
		lastNoHave = curNoHave
	}

	return lastNoHave
}
