#include "node.h"

#include <iostream>

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

template<typename T, T AFunc(T)>
Node<T, AFunc>::Node() noexcept
    : potential_(T()),
      response_(T()),
      inputs_(nullptr)
{}

//template<typename T, T AFunc(T)>
//T Node<T, AFunc>::potential() const
//{
//    return potential_;
//}

//template<typename T, T AFunc(T)>
//void Node<T, AFunc>::set_potential(T potential)
//{
//    potential_ = potential;
//}

//template<typename T, T AFunc(T)>
//T Node<T, AFunc>::response() const
//{
//    return response_;
//}

template<typename T, T AFunc(T)>
void Node<T, AFunc>::update()
{
    if (inputs_ == nullptr) {
        std::cerr << __PRETTY_FUNCTION__ << " cannot update a node without initialized inputs\n";
        return;
    }

    std::size_t size = weights_.size();
    std::size_t n = (size + 7) / 8;
    auto weight_it = weights_.end();
    auto input_it = (*inputs_).end();

    auto update_weight = [&]() {
        potential_ += *--weight_it * *--input_it;
    };

    switch  (size % 8) {
      case 0:
        do {
            update_weight();
      case 7:
            update_weight();
      case 6:
            update_weight();
      case 5:
            update_weight();
      case 4:
            update_weight();
      case 3:
            update_weight();
      case 2:
            update_weight();
      case 1:
            update_weight();
        } while (--n > 0);
    }

    cassert(weight_it == weights_.begin());
    cassert(input_it == (*inputs_).begin());

    response_ = AFunc(potential_);
}

template class NodeOutput<float>;
template class NodeOutput<double>;
template class NodeOutput<long double>;

} // namespace qlnet
