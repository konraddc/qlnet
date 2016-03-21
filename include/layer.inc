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
auto InputLayer<T>::output() const -> const NodeOutputRefs<T>&
{
    return outputs_;
}

template<typename T, typename TFunc>
Layer<T, TFunc>::Layer(std::size_t node_count)
    : nodes_(node_count)
{
    for (const node_type&node : nodes_) {
        outputs_.push_back(node.output());
    }
}

template<typename T, typename TFunc>
void Layer<T, TFunc>::connect(const NodeOutputRefs<T> &outputs)
{
    for (node_type &node : nodes_) {
        node.connect(outputs);
    }
}

template<typename T, typename TFunc>
auto Layer<T, TFunc>::output() const -> const NodeOutputRefs<T>&
{
    return outputs_;
}

template<typename T, typename TFunc>
auto Layer<T, TFunc>::nodes() -> NodeContainer<node_type>&
{
    return nodes_;
}

template<typename T, typename TFunc>
void Layer<T, TFunc>::update()
{
    for (node_type &node : nodes_) {
        node.update();
    }
}
