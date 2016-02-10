#ifndef PATTERNSET_H
#define PATTERNSET_H

#include <vector>

namespace qlnet {

template<typename T>
class PatternSet
{
    typedef std::pair<std::vector<T>, std::vector<T>> Pattern;

public:
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
    int count() const;

    /**
     * @brief Get i-th Pattern
     * @param index
     * @return Pattern
     */
    const Pattern& operator[](int i) const;

private:
    std::vector<Pattern> patterns_;
};

} // namespace qlnet

#endif // PATTERNSET_H
