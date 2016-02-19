#ifndef QLNET_NODE_H_
#define QLNET_NODE_H_

#include <cstddef>
#include <vector>

#include "nodeoutput.h"

namespace qlnet {

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
    NodeOutput<T> response() const;

    /**
     * @brief connect
     * @param outputs
     */
    inline void connect(std::vector<NodeOutput<T>>* outputs);

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
