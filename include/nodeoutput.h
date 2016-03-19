#ifndef QLNET_NODEOUTPUT_H_
#define QLNET_NODEOUTPUT_H_

#include <vector>

namespace qlnet {

/**
 * @brief The NodeOutput class
 * a reference wrapper around
 * the Nodes' response value
 */
template<typename T>
class NodeOutputRef
{
public:
    /**
     * @brief constructor
     * @param value_ref
     */
    NodeOutputRef(const T& value_ref) noexcept;

    /**
     * @brief deleted constructor
     * don't wrap rvalues
     */
    NodeOutputRef(T&&) = delete;

    /**
     * @brief defaulted copy constructor
     */
    NodeOutputRef(const NodeOutputRef&) noexcept = default;

    /**
     * @brief defaulted equal operator
     */
    NodeOutputRef& operator=(const NodeOutputRef&) noexcept = default;

    /**
     * @brief accesing the value
     */
    operator const T&() const noexcept;

private:
    const T* value_ptr_;
};

template<class T>
using NodeOutputRefs = std::vector<NodeOutputRef<T>>;

} // namespace qlnet

#endif // QLNET_NODEOUTPUT_H_
