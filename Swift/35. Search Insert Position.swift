// 35. Search Insert Position
// 16 ms， 52.88%
return nums.map({$0 - target}).filter({$0 < 0}).count