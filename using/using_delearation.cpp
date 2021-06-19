#include <vector>
using namespace std;
template <typename _Alloc>
class vector<bool, _Alloc> : protected _Bvector_base<_Alloc>
{
    typedef _Bvector_base<_Alloc> _Base;
    typedef typename _Base::_BitPointer _BitPointer;
    typedef typename _Base::_Bit_alloc_traits _Bit_alloc_traits;

protected:
    using _Base::_M_allocate;
    using _Base::_M_deallocate;
    using _Base::_M_get_Bit_allocator;
    using _Base::_S_nword;
};