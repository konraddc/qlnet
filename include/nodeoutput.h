#ifndef QLNET_NODEOUTPUT_H_
#define QLNET_NODEOUTPUT_H_

namespace qlnet {

/**
 * @brief The NodeOutput class
 * a reference wrapper around
 * the Nodes' response value
 */
template<typename T>
class NodeOutput
{
public:
    /**
     * @brief constructor
     * @param value_ref
     */
    NodeOutput(const T& value_ref) noexcept;

    /**
     * @brief deleted constructor
     * don't wrap rvalues
     */
    NodeOutput(T&&) = delete;

    /**
     * @brief defaulted copy constructor
     */
    NodeOutput(const NodeOutput&) noexcept = default;

    /**
     * @brief defaulted equal operator
     */
    NodeOutput& operator=(const NodeOutput&) noexcept = default;

    /**
     * @brief accesing the value
     */
    operator const T&() const noexcept;

private:
    const T* value_ptr_;
};

} // namespace qlnet

#endif // QLNET_NODEOUTPUT_H_
