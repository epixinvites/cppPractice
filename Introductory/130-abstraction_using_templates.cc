template<typename Iter, typename Val> Val accumulate(Iter first, Iter last, Val res){
    for(auto p = first; p!=last; ++p){
        res+=*p;
    }
    return res;
}
