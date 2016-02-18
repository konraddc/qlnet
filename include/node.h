#ifndef QLNET_NODE_H_
#define QLNET_NODE_H_

#include <cstddef>
#include <vector>

namespace qlnet {


/**
 * @brief The NodeOutput class
 * is a reference wrapper
 * around the Nodes' response value
 */
template<typename T>
class NodeOutput
{
public:
    inline NodeOutput(T& value_ref) noexcept;
    NodeOutput(T&&) = delete;
    NodeOutput(const NodeOutput&) noexcept = default;
    NodeOutput& operator=(const NodeOutput&) noexcept = default;

    inline operator T&() const noexcept;

    static T func_a(T v) { return v; }

private:
    T* value_ptr_;
};

template<typename T>
using NodeInput = NodeOutput<T>;

template<typename T, T AFunc(T)>
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
    NodeOutput<T> output();

    /**
     * @brief connect
     * @param outputs
     */
    inline void connect(std::vector<NodeOutput<T>>* outputs);

    // TODO: is potential and response needed?
//    /**
//     * @brief potential
//     * @return current potential
//     */
//    inline T potential() const;

//    /**
//     * @brief set_potential
//     * @param potential new potential
//     */
//    inline void set_potential(T potential);

//    /**
//     * @brief response
//     * response for the current potential
//     * using AFunc (an activation function)
//     * @return current response
//     */
//    inline T response() const;

    /**
     * @brief update node potential and calculate response
     */
    void update();

private:
    T potential_;
    T response_;
    std::vector<NodeInput<T>>* inputs_; // TODO: consider only one input layer for now
    std::vector<T> weights_;
};

} // namespace qlnet

#endif // QLNET_NODE_H_
