template<typename T, typename TFunc>
Node<T, TFunc>::Node() noexcept
    : net_(T()),
      output_(T()),
      inputs_(nullptr)
{}

template<typename T, typename TFunc>
Node<T, TFunc>::Node(std::vector<T> &weights) noexcept
    : net_(T()),
      output_(T()),
      inputs_(nullptr),
      weights_(std::move(weights))
{}

template<typename T, typename TFunc>
Node<T, TFunc>::Node(std::vector<T> &&weights) noexcept
    : net_(T()),
      output_(T()),
      inputs_(nullptr),
      weights_(std::move(weights))
{}

template<typename T, typename TFunc>
Node<T, TFunc>::Node(const std::vector<T> &weights) noexcept
    : net_(T()),
      output_(T()),
      inputs_(nullptr),
      weights_(weights)
{}

template<typename T, typename TFunc>
NodeOutputRef<T> Node<T, TFunc>::output() const
{
    return output_;
}

template<typename T, typename TFunc>
void Node<T, TFunc>::connect(const NodeOutputRefs<T> &outputs)
{
    inputs_ = std::addressof(outputs);
}

template<typename T, typename TFunc>
void Node<T, TFunc>::init_weights(std::vector<T> &weights)
{
    weights_ = std::move(weights);
}

template<typename T, typename TFunc>
void Node<T, TFunc>::init_weights(std::vector<T> &&weights)
{
    weights_ = std::move(weights);
}

template<typename T, typename TFunc>
void Node<T, TFunc>::init_weights(const std::vector<T> &weights)
{
    weights_ = weights;
}

template<typename T, typename TFunc>
template<typename Rand>
void Node<T, TFunc>::randomize_weights(Rand rand)
{
    if (inputs_ == nullptr) {
        std::cerr << __PRETTY_FUNCTION__ << " cannot randomize weights without initialized inputs\n";
        return;
    }

    for (int i = 0; i < inputs_->size(); ++i) {
        weights_.push_back(rand());
    }
}

template<typename T, typename TFunc>
void Node<T, TFunc>::update()
{
    // TODO: remove this check, leave an assert
    if (inputs_ == nullptr || (weights_.size() != inputs_->size())) {
        std::cerr << __PRETTY_FUNCTION__ << " cannot update a node without initialized inputs or weights\n";
        return;
    }

    std::size_t size = inputs_->size();
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

    // TODO: remove this assert
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
