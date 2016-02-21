#include "nodeoutput.h"

#include <memory>

#include <iostream>

namespace  qlnet {

template<typename T>
NodeOutput<T>::NodeOutput(const T& value_ref) noexcept
    : value_ptr_(std::addressof(value_ref))
{}

template<typename T>
NodeOutput<T>::operator const T&() const noexcept
{
    return *value_ptr_;
}

// Explicit template instantiations
template class NodeOutput<float>;
template class NodeOutput<double>;
template class NodeOutput<long double>;

} // namespace  qlnet
