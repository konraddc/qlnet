template<typename TInput, typename TOutput>
bool PatternSet<TInput,TOutput>::read(std::string input)
{
    std::ifstream file(input);
    if(!file.good())
        return false;

    // TODO: this is wrong and error prone, get a proper file format and parser for this
    file >> input_size_;
    file >> output_size_;
    bool read_more = true;
    while (read_more && !file.eof()) {
        pattern_type pattern (input_size_, output_size_);
        for (int i = 0; i < input_size_; ++i) {
            typename pattern_type::input_type input_value;
            file >> input_value;
            if (file.eof() || !pattern.push_input(input_value)) {
                read_more = false;
                break;
            }
        }

        for (int i = 0; i < output_size_; ++i) {
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
