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

    // TODO: make an alias for vector<T> weigths
    /**
     * @brief construct Node with initial weights
     * @param weights to move into a node, left in unspecified state after the call
     */
    Node(std::vector<T> &weights) noexcept;
    Node(std::vector<T> &&weights) noexcept;

    /**
     * @brief construct Node with initial weights
     * @param weights to copy into a node
     */
    Node(const std::vector<T> &weights) noexcept;

    /**
     * @brief output
     * @return node output
     */
    NodeOutputRef<T> output() const;

    /**
     * @brief assign input
     * @param outputs from other nodes
     */
    void connect(const NodeOutputRefs<T> &outputs);

    /**
     * @brief init_weights
     * @param weights to move into a node, left in unspecified state after the call
     */
    void init_weights(std::vector<T> &weights);
    void init_weights(std::vector<T> &&weights);

    /**
     * @brief init_weights
     * @param weights to copy into the node
     */
    void init_weights(const std::vector<T> &weights);

    /**
     * @brief update node potential and calculate response
     */
    void update();

private:
    T net_;
    T output_;
    const NodeOutputRefs<T>* inputs_; // TODO: only one input layer for now
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
