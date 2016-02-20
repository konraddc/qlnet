#ifndef QLNET_NODE_H_
#define QLNET_NODE_H_

#include <cstddef>
#include <cassert>
#include <vector>
#include <iostream>

#include "nodeoutput.h"

namespace qlnet {

template<typename T, typename TFunc>
class Node
{
public:
    /**
     * @brief defaulted constructor
     * @param input_size number of inputs
     */
    Node() noexcept;

    /**
     * @brief output
     * @return node output
     */
    NodeOutput<T> response() const;

    /**
     * @brief connect
     * @param outputs
     */
    void connect(std::vector<NodeOutput<T>>* outputs, T initial_weight = 0);

    /**
     * @brief update node potential and calculate response
     */
    void update();

private:
    T net_;
    T response_;
    std::vector<NodeInput<T>>* inputs_; // TODO: only one input layer for now
    std::vector<T> weights_;
};

// template definitions
#include "node.inc"

} // namespace qlnet

#endif // QLNET_NODE_H_
