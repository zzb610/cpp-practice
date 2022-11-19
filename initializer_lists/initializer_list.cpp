// 仿写标准库的initializer_list

template <typename _E>
class initializer_list
{
    typedef _E value_type;
    typedef const _E &reference;
    typedef const _E &const_reference;
    typedef size_t size_type;
    typedef const _E *iterator;
    typedef const _E *const_iterator;

private:
    iterator _M_array;
    size_type _M_len;
    // 编译器可以调用私有的构造方法
    constexpr initializer_list(const_iterator __a, size_type __l): _M_array(__a), _M_len(__l)
    {

    }
public:
    constexpr initializer_list() noexcept
    :_M_array(0), _M_len(0){}

    constexpr size_type size() const noexcept
    {
        return _M_len;
    }

    constexpr const_iterator begin() const noexcept
    {
        return _M_array;
    }
    constexpr const_iterator end() const noexcept
    {
        return _M_array + _M_len;
    }
};