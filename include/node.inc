template<typename T, typename TFunc>
Node<T, TFunc>::Node() noexcept
    : net_(T()),
      output_(T()),
      inputs_(nullptr)
{}

template<typename T, typename TFunc>
NodeOutputRef<T> Node<T, TFunc>::output() const
{
    return output_;
}

template<typename T, typename TFunc>
void Node<T, TFunc>::connect(const std::vector<NodeOutputRef<T>> &outputs, T initial_weight)
{
    inputs_ = std::addressof(outputs);
    weights_.resize(outputs.size(), initial_weight);
}

template<typename T, typename TFunc>
void Node<T, TFunc>::update()
{
    if (inputs_ == nullptr) {
        std::cerr << __PRETTY_FUNCTION__ << " cannot update a node without initialized inputs\n";
        return;
    }

    std::size_t size = weights_.size();
    std::size_t n = (size + 7) / 8;
    auto weight_it = weights_.end();
    auto input_it = inputs_->end();

    auto update_weight = [&]() {
        net_ += *--weight_it * *--input_it;
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

    assert(weight_it == weights_.begin());
    assert(input_it == inputs_->begin());

    output_ = TFunc::eval(net_);
}

template<typename T>
InputNode<T>::InputNode() noexcept
    : output_(T())
{}

template<typename T>
void InputNode<T>::set_output(T output)
{
    output_ = output;
}

template<typename T>
NodeOutputRef<T> InputNode<T>::output() const
{
    return output_;
}
