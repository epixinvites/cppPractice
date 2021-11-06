template<Sequence Seq, Number Num> requires Arithmetic<Value_type<Seq>, Num>
Num sum(Seq s, Num v){
    for(const auto &x:s){
        v+=x;
    }
    return v;
}
