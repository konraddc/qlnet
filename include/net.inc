//std::random_device rd;
//std::mt19937 gen(rd());
//std::uniform_int_distribution<> dis(1, 6);

template<typename T>
Net<T>::Net()
    : input_layer_(nullptr)
{}

template<typename T>
std::vector<T> Net<T>::evaluate(std::vector<T> input)
{
    std::vector<T> output;
    if(!input_layer_) {
        std::cerr << __PRETTY_FUNCTION__ << " trying to use a network without specifying the input layer\n";
        return output;
    }

    input_layer_->set_input(input);
    for (auto layer : hidden_layers_) {
        layer->update();
    }

    output.reserve(hidden_layers_.back()->output().size());
    for (auto o : hidden_layers_.back()->output()) {
        output.push_back(o);
    }

    return output;
}

template<typename T>
void Net<T>::set_input_layer(InputLayer<T> *input_layer)
{
    input_layer_ = input_layer;
}

template<typename T>
void Net<T>::add_hidden_layer(AbstractLayer<T> *layer)
{
    if(!input_layer_) {
        std::cerr << __PRETTY_FUNCTION__ << " trying to add a hidden layer without specifying the input\n";
        return;
    }

    if(hidden_layers_.empty()) {
        layer->connect(input_layer_->output());
    } else {
        layer->connect(hidden_layers_.back()->output());
    }

    hidden_layers_.push_back(layer);
}
