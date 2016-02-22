#include "nodeoutput.h"

#include <memory>

namespace  qlnet {

template<typename T>
NodeOutputRef<T>::NodeOutputRef(const T& value_ref) noexcept
    : value_ptr_(std::addressof(value_ref))
{}

template<typename T>
NodeOutputRef<T>::operator const T&() const noexcept
{
    return *value_ptr_;
}

// Explicit template instantiations
template class NodeOutputRef<float>;
template class NodeOutputRef<double>;
template class NodeOutputRef<long double>;

} // namespace  qlnet
