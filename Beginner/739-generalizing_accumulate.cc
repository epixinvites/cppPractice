template<typename ln, typename T, typename BinOp>T accumulate(ln first, ln last, T init, BinOp op){
    while(first!=last){
	init=op(init, *first);
	++first;
    }
    return init;
}
