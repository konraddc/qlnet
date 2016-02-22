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
    const std::vector<NodeOutputRef<T>>& outputs() const;

private:
    std::vector<NodeOutputRef<T>> outputs_;
    std::deque<InputNode<T>> nodes_;
};

template<typename T, typename TFunc>
class Layer
{
public:
    /**
     * @brief constructor
     * @param input_size number of input elements
     */
    Layer(std::size_t node_count);

    /**
     * @brief assign inputs
     * @param outputs from other layer
     */
    void connect(const std::vector<NodeOutputRef<T>> &outputs, T initial_weight = 0);

    /**
     * @brief outputs
     * @return vector of node output reference wrappers
     */
    const std::vector<NodeOutputRef<T>>& outputs() const;

    /**
     * @brief update nodes potentials and calculate responses
     */
    void update();

private:
    std::vector<NodeOutputRef<T>> outputs_;
    std::deque<Node<T, TFunc>> nodes_;
};

// template definitions
#include "layer.inc"

} // namespace qlnet

#endif // QLNET_LAYER_H_

