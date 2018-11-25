// 771. Jewels and Stones
// 20 ms
return J.reduce(0) { sum, j in
            sum + S.filter({$0 == j}).count
        }
