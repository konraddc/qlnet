#include "nodeoutput.h"

#include <memory>

namespace  qlnet {

template<typename T>
NodeOutput<T>::NodeOutput(T& value_ref) noexcept
    : value_ptr_(std::addressof(value_ref))
{}

template<typename T>
NodeOutput<T>::operator T&() const noexcept
{
    return *value_ptr_;
}

template class NodeOutput<float>;
template class NodeOutput<double>;
template class NodeOutput<long double>;

} // namespace  qlnet
