#ifndef QLNET_PATTERN_H_
#define QLNET_PATTERN_H_

// TODO: using deque could be more memmory efficient for large data set (less chance for bad_alloc)
#include <vector>
#include <iostream>

namespace qlnet {

template<typename TInput, typename TOutput = TInput>
class Pattern
{
public:
    typedef TInput input_type;
    typedef TOutput output_type;

    /**
     * @brief Pattern initialize with requeried input/output sizes
     * @param input_size
     * @param output_size
     */
    Pattern(std::size_t input_size, std::size_t output_size);

    /**
     * @brief Append an input value
     * @param input_value
     * @return false if inputs are already full
     */

    bool push_input(input_type input_value);

    /**
     * @brief Append an output value
     * @param output_value
     * @return false if output are already full
     */
    bool push_output(output_type output_value);

    /**
     * @brief inputs
     * @return inputs vector
     */
    const std::vector<input_type>& input() const;

    /**
     * @brief outputs
     * @return outputs vector
     */
    const std::vector<output_type>& output() const;

    /**
     * @brief input_at get i-th element
     * @param i index of element
     * @return input element at index i
     */
    const input_type& input_at(std::size_t i) const;

    /**
     * @brief output_at get i-th element
     * @param i index of element
     * @return output element at index i
     */
    const output_type& output_at(std::size_t i) const;

    /**
     * @brief input_size
     * @return number of input elements
     */
    std::size_t input_size() const;

    /**
     * @brief output_size
     * @return number of output elements
     */
    std::size_t output_size() const;

private:
    std::vector<input_type> input_;
    std::vector<output_type> output_;
    std::size_t input_size_;
    std::size_t output_size_;
};

// template definitions
#include "pattern.inc"

} // namespace qlnet

#endif // QLNET_PATTERN_H_
