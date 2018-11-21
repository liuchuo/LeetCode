// 657. Judge Route Circle
// 236 ms
return moves.filter({$0 == "U"}).count == moves.filter({$0 == "D"}).count && moves.filter({$0 == "R"}).count == moves.filter({$0 == "L"}).count