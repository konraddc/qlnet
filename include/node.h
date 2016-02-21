#ifndef QLNET_NODE_H_
#define QLNET_NODE_H_

#include <cstddef>
#include <cassert>
#include <vector>
#include <iostream>

#include "nodeoutput.h"
#include "transferfunc.h"

namespace qlnet {

template<typename T, typename TFunc>
class Node
{
public:
    /**
     * @brief constructor
     */
    Node() noexcept;

    /**
     * @brief output
     * @return node output
     */
    NodeOutput<T> response() const;

    /**
     * @brief assign input
     * @param outputs from other nodes
     */
    void connect(const std::vector<NodeOutput<T>> &outputs, T initial_weight = 0);

    /**
     * @brief update node potential and calculate response
     */
    void update();

private:
    T net_;
    T response_;
    const std::vector<NodeOutput<T>>* inputs_; // TODO: only one input layer for now
    std::vector<T> weights_;
};

template<typename T>
class InputNode
{
public:
    /**
     * @brief constructor
     */
    InputNode() noexcept;

    /**
     * @brief set_input
     * @param input
     */
    void set_output(T output);

    /**
     * @brief output
     * @return node output
     */
    NodeOutput<T> output() const;

private:
    T output_;
};

// template definitions
#include "node.inc"

} // namespace qlnet

#endif // QLNET_NODE_H_
