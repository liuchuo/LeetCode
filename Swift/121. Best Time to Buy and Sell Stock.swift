// 121. Best Time to Buy and Sell Stock
// 16 ms, 90.40%
func maxProfit(_ prices: [Int]) -> Int {
    if prices.count < 2 { return 0 }

    var p = prices[0], m = 0
    for i in 1..<prices.count {
        m = max(m, prices[i] - p)
        p = min(p, prices[i])
    }
    return m
}