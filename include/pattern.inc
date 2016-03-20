template<typename TInput, typename TOutput>
Pattern<TInput,TOutput>::Pattern(size_t input_size, size_t output_size)
    : input_size_(input_size),
      output_size_(output_size)
{
    input_.reserve(input_size);
    output_.reserve(output_size);
}

template<typename TInput, typename TOutput>
Pattern<TInput,TOutput>::Pattern(const std::vector<input_type> &input, const std::vector<output_type> &output)
    : input_size_(input.size()),
      output_size_(output.size()),
      input_(input),
      output_(output)
{}

template<typename TInput, typename TOutput>
Pattern<TInput,TOutput>::Pattern(std::vector<input_type> &input, std::vector<output_type> &output)
    : input_size_(input.size()),
      output_size_(output.size()),
      input_(std::move(input)),
      output_(std::move(output))
{}

template<typename TInput, typename TOutput>
Pattern<TInput,TOutput>::Pattern(std::vector<input_type> &&input, std::vector<output_type> &&output)
    : input_size_(input.size()),
      output_size_(output.size()),
      input_(std::move(input)),
      output_(std::move(output))
{}

template<typename TInput, typename TOutput>
bool Pattern<TInput,TOutput>::push_input(input_type input_value)
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
bool Pattern<TInput,TOutput>::push_output(output_type output_value)
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
auto Pattern<TInput,TOutput>::input() const -> const std::vector<input_type>&
{
    return input_;
}

template<typename TInput, typename TOutput>
auto Pattern<TInput,TOutput>::output() const -> const std::vector<output_type>&
{
    return output_;
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
