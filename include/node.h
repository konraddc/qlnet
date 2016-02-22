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
    NodeOutputRef<T> output() const;

    /**
     * @brief assign input
     * @param outputs from other nodes
     */
    void connect(const std::vector<NodeOutputRef<T>> &outputs, T initial_weight = 0);

    /**
     * @brief update node potential and calculate response
     */
    void update();

private:
    T net_;
    T output_;
    const std::vector<NodeOutputRef<T>>* inputs_; // TODO: only one input layer for now
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
    NodeOutputRef<T> output() const;

private:
    T output_;
};

// template definitions
#include "node.inc"

} // namespace qlnet

#endif // QLNET_NODE_H_
