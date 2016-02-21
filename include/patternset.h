#ifndef QLNET_PATTERNSET_H_
#define QLNET_PATTERNSET_H_

#include <vector>
#include <fstream>
#include <iostream>

#include "pattern.h"

namespace qlnet {

template<typename TInput, typename TOutput = TInput>
class PatternSet
{
public:
    typedef Pattern<TInput,TOutput> pattern_type;

    PatternSet() noexcept = default;

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

// template definitions
#include "patternset.inc"

} // namespace qlnet

#endif // QLNET_PATTERNSET_H_
