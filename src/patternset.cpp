#include "patternset.h"

#include <fstream>
#include <iostream>

namespace qlnet {

template<typename TInput, typename TOutput>
Pattern<TInput, TOutput>::Pattern(size_t input_size, size_t output_size)
    : input_size_(input_size), output_size_(output_size)
{
    input_.reserve(input_size);
    output_.reserve(output_size);
}

template<typename TInput, typename TOutput>
bool Pattern<TInput, TOutput>::push_input(input_type input_value)
{
    if (input_.size() < input_size_) {
        input_.push_back(input_value);
    } else {
        std::cerr << __PRETTY_FUNCTION__ << " cannot push elements past the declared size\n";
        return false;
    }

    return true;
}

template<typename TInput, typename TOutput>
bool Pattern<TInput, TOutput>::push_output(input_type output_value)
{
    if (output_.size() < output_size_) {
        output_.push_back(output_value);
    } else {
        std::cerr << __PRETTY_FUNCTION__ << " cannot push elements past the declared size\n";
        return false;
    }

    return true;
}

template<typename TInput, typename TOutput>
auto Pattern<TInput,TOutput>::input_at(std::size_t i) const -> const input_type&
{
    return input_.at(i);
}

template<typename TInput, typename TOutput>
auto Pattern<TInput,TOutput>::output_at(std::size_t i) const -> const output_type&
{
    return output_.at(i);
}

template<typename TInput, typename TOutput>
std::size_t Pattern<TInput,TOutput>::input_size() const
{
    return input_.size();
}

template<typename TInput, typename TOutput>
std::size_t Pattern<TInput,TOutput>::output_size() const
{
    return output_.size();
}

template<typename TInput, typename TOutput>
PatternSet<TInput,TOutput>::PatternSet()
{}

template<typename TInput, typename TOutput>
bool PatternSet<TInput,TOutput>::read(std::string input)
{
    std::ifstream file(input);
    if(!file.good())
        return false;

    size_t inputs_size = 0, outputs_size = 0;
    file >> inputs_size;
    file >> outputs_size;

    bool read_more = true;
    while (read_more) {
        pattern_type pattern (inputs_size, outputs_size);
        for (int i = 0; i < inputs_size; ++i) {
            typename pattern_type::input_type input_value;
            file >> input_value;
            if (file.eof() || !pattern.push_input(input_value)) {
                read_more = false;
                break;
            }
        }

        for (int i = 0; i < outputs_size; ++i) {
            typename pattern_type::output_type output_value;
            file >> output_value;
            if (file.eof() || !pattern.push_output(output_value)) {
                read_more = false;
                break;
            }
        }

        if (read_more)
            patterns_.push_back(pattern);
    }
    return true;
}

template<typename TInput, typename TOutput>
std::size_t PatternSet<TInput,TOutput>::size() const
{
    return patterns_.size();
}

template<typename TInput, typename TOutput>
std::size_t PatternSet<TInput,TOutput>::input_size() const
{
    return input_size_;
}

template<typename TInput, typename TOutput>
std::size_t PatternSet<TInput,TOutput>::output_size() const
{
    return output_size_;
}

template<typename TInput, typename TOutput>
auto PatternSet<TInput,TOutput>::operator[](int i) const -> const pattern_type&
{
    return patterns_.at(i);
}

// Explicit template instantiations
template class Pattern<int32_t>;
template class Pattern<int64_t>;
template class Pattern<float>;
template class Pattern<double>;

template class PatternSet<int32_t>;
template class PatternSet<int64_t>;
template class PatternSet<float>;
template class PatternSet<double>;

} // namespace qlnet
