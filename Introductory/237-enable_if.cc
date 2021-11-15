#include <type_traits>
template<typename T> class Smart_pointer{
    T &operator*();
    std::enable_if<std::is_class<T>::value, T&> operator->();
};
