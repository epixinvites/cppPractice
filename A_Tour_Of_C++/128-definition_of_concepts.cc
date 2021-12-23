#include <concepts>
#include <iterator>
template<typename S> concept Sequence = requires(S a){
    typename Value_type<S>;
    typename Iterator_type<S>;
    {std::begin(a)} -> Iterator_type<S>;
    {std::end(a)} -> Iterator_type<S>;

    requires Same_type<Value_type<S>, Value_type<Iterator_type<S>>>;
    requires Input_iterator<Iterator_type<S>>;
};
