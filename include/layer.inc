template<typename T>
InputLayer<T>::InputLayer(std::size_t input_size)
    : nodes_(input_size)
{
    for (const InputNode<T>&node : nodes_) {
        outputs_.push_back(node.output());
    }
}

template<typename T>
void InputLayer<T>::set_input(const std::vector<T>& input)
{
    assert (input.size() == outputs_.size());

    auto node = nodes_.begin();
    for (auto input_value : input) {
        node++->set_output(input_value);
    }
}

template<typename T>
auto InputLayer<T>::outputs() const -> const std::vector<NodeOutputRef<T>>&
{
    return outputs_;
}

template<typename T, typename TFunc>
Layer<T, TFunc>::Layer(std::size_t node_count)
    : nodes_(node_count)
{
    for (const Node<T, TFunc>&node : nodes_) {
        outputs_.push_back(node.output());
    }
}

template<typename T, typename TFunc>
void Layer<T, TFunc>::connect(const std::vector<NodeOutputRef<T>> &outputs, T initial_weight)
{
    for (Node<T, TFunc>&node : nodes_) {
        node.connect(outputs, initial_weight);
    }
}

template<typename T, typename TFunc>
auto Layer<T, TFunc>::outputs() const -> const std::vector<NodeOutputRef<T>>&
{
    return outputs_;
}

template<typename T, typename TFunc>
void Layer<T, TFunc>::update()
{
    for (Node<T, TFunc>&node : nodes_) {
        node.update();
    }
}
