#ifndef QLNET_LAYER_H_
#define QLNET_LAYER_H_

#include <deque>
#include <functional>

#include "nodeoutput.h"
#include "node.h"

namespace qlnet {

// TODO: consider a dynamic array instead
// Any container that doesn't reallocate elements is good
// deque is big for really small amount of nodes
template<class TNode>
using NodeContainer = std::deque<TNode>;

template<typename T>
class InputLayer
{
public:
    typedef InputNode<T> node_type;

    /**
     * @brief constructor
     * @param input_size number of input elements
     */
    InputLayer(std::size_t input_size);

    // TODO: use Pattern etc. as input
    /**
     * @brief set_input
     * @param input new input
     */
    void set_input(const std::vector<T> &input);

    /**
     * @brief outputs
     * @return vector of node output reference wrappers
     */
    const NodeOutputRefs<T>& outputs() const;

private:
    NodeOutputRefs<T> outputs_;
    NodeContainer<node_type> nodes_;
};

template<typename T, typename TFunc>
class Layer
{
public:
    typedef Node<T, TFunc> node_type;

    /**
     * @brief constructor
     * @param input_size number of input elements
     */
    Layer(std::size_t node_count);

    /**
     * @brief assign input layer
     * @param outputs from other layer
     */
    void connect(const NodeOutputRefs<T> &outputs);

    /**
     * @brief outputs
     * @return node output reference wrappers
     */
    const NodeOutputRefs<T> &outputs() const;

    /**
     * @brief nodes
     * @return nodes of the layer
     */
    NodeContainer<node_type> &nodes();

    /**
     * @brief update nodes potentials and calculate responses
     */
    void update();

private:
    NodeOutputRefs<T> outputs_;
    NodeContainer<node_type> nodes_;
};

// template definitions
#include "layer.inc"

} // namespace qlnet

#endif // QLNET_LAYER_H_

