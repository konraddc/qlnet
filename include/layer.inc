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
const std::vector<NodeOutput<T>>& InputLayer<T>::outputs() const
{
    return outputs_;
}
