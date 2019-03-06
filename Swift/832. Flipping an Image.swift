// 832. Flipping an Image
// 16 ms
return A.map({$0.map({1-$0}).reversed()})