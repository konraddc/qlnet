#ifndef QLNET_PATTERNSET_H_
#define QLNET_PATTERNSET_H_

// TODO: using deque could be more memmory efficient for large data set (less chance for bad_alloc)
// TODO: do performance checks with deque and/or self dynamic array impl
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
    Pattern(size_t input_size, size_t output_size);

    /**
     * @brief Append an input value
     * @param input_value
     * @return false if inputs are already full
     */
    inline bool push_input(input_type input_value);
    /**
     * @brief Append an output value
     * @param output_value
     * @return false if output are already full
     */
    inline bool push_output(input_type output_value);
    /**
     * @brief input_at get i-th element
     * @param i index of element
     * @return input element at index i
     */
    inline const input_type& input_at(std::size_t i) const;
    /**
     * @brief output_at get i-th element
     * @param i index of element
     * @return output element at index i
     */
    inline const output_type& output_at(std::size_t i) const;
    /**
     * @brief input_size
     * @return number of input elements
     */
    inline std::size_t input_size() const;
    /**
     * @brief output_size
     * @return number of output elements
     */
    inline std::size_t output_size() const;

private:
    std::vector<input_type> input_;
    std::vector<output_type> output_;
    std::size_t input_size_;
    std::size_t output_size_;
};

template<typename TInput, typename TOutput = TInput>
class PatternSet
{
public:
    typedef Pattern<TInput,TOutput> pattern_type;

    PatternSet();

    /**
     * @brief Read patters from file
     * @param input text file with pattern descriptions
     * @return true if success
     */
    bool read(std::string input);

    /**
     * @brief Patterns count
     * @return number of pattenrs
     */
    std::size_t size() const;

    /**
     * @brief Inputs count
     * @return number of input values
     */
    std::size_t input_size() const;

    /**
     * @brief Outputs count
     * @return number of output values
     */
    std::size_t output_size() const;

    /**
     * @brief Get i-th Pattern
     * @param index
     * @return Pattern
     */
    const pattern_type& operator[](int i) const;

private:
    std::vector<pattern_type> patterns_;
    std::size_t input_size_;
    std::size_t output_size_;
};

} // namespace qlnet

#endif // QLNET_PATTERNSET_H_
