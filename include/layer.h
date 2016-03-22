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
template<typename TNode>
using NodeContainer = std::deque<TNode>;

template<typename T>
class AbstractLayer
{
public:
    AbstractLayer() noexcept = default;
    AbstractLayer(AbstractLayer&&) = delete;
    AbstractLayer(const AbstractLayer&) = delete;
    AbstractLayer& operator=(const AbstractLayer&) = delete;

    virtual void connect(const NodeOutputRefs<T> &output) = 0;
    virtual const NodeOutputRefs<T>& output() const = 0;
    virtual void update() = 0;
};

template<typename T>
class InputLayer/* : public AbstractLayer<T>*/
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
    virtual const NodeOutputRefs<T>& output() const/* override*/;

private:
    NodeOutputRefs<T> outputs_;
    NodeContainer<node_type> nodes_;
};

template<typename T, typename TFunc>
class HiddenLayer : public AbstractLayer<T>
{
public:
    typedef Node<T, TFunc> node_type;

    /**
     * @brief constructor
     * @param input_size number of input elements
     */
    HiddenLayer(std::size_t node_count);

    /**
     * @brief assign input layer
     * @param outputs from other layer
     */
    virtual void connect(const NodeOutputRefs<T> &output) override;

    /**
     * @brief outputs
     * @return node output reference wrappers
     */
    virtual const NodeOutputRefs<T> &output() const override;

    /**
     * @brief nodes
     * @return nodes of the layer
     */
    NodeContainer<node_type> &nodes();

    /**
     * @brief update nodes potentials and calculate responses
     */
    void update() override;

private:
    NodeOutputRefs<T> outputs_;
    NodeContainer<node_type> nodes_;
};

// template definitions
#include "layer.inc"

} // namespace qlnet

#endif // QLNET_LAYER_H_

