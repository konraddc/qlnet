#ifndef QLNET_NET_H_
#define QLNET_NET_H_

#include "layer.h"

namespace qlnet {

// TODO: this needs a complete rewrite
// TODO: overload a Net>>Layer operator to make easy layer to layer connections;
template<typename T>
class Net
{
public:
    Net();
    std::vector<T> evaluate(std::vector<T> input);
    void set_input_layer(InputLayer<T> *input_layer);
    void add_hidden_layer(AbstractLayer<T> *layer);
private:
    InputLayer<T> *input_layer_;
    std::vector<AbstractLayer<T>*> hidden_layers_;
};

// template definitions
#include "net.inc"

} // namespace qlnet

#endif // QLNET_NET_H_
