#ifndef QLNET_LAYER_H_
#define QLNET_LAYER_H_

#include <deque>

#include "node.h"

namespace qlnet {

template<typename T>
class InputLayer
{
public:
    /**
     * @brief constructor
     * @param input_size number of input elements
     */
    InputLayer(std::size_t input_size);

    /**
     * @brief set_input
     * @param input new input
     */
    void set_input(const std::vector<T>& input);

    /**
     * @brief outputs
     * @return vector of node output reference wrappers
     */
    const std::vector<NodeOutput<T>>& outputs() const;

private:
    std::vector<NodeOutput<T>> outputs_;
    std::deque<InputNode<T>> nodes_;
};

template<typename T, typename TFunc>
class Layer
{

};

// template definitions
#include "layer.inc"

} // namespace qlnet

#endif // QLNET_LAYER_H_

