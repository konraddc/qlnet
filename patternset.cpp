#include "patternset.h"

#include <fstream>
#include <iostream>

namespace qlnet {

template<typename T>
inline PatternSet<T>::PatternSet()
{

}

template<typename T>
bool PatternSet<T>::read(std::string input)
{
    std::cout << input << "\n";
    std::ifstream file(input);
    if(!file.good())
        return false;

    int inputs_num = 0, outputs_num = 0;
    file >> inputs_num;
    file >> outputs_num;
    std::cout << inputs_num << ' ' << outputs_num << '\n';

    int dupa = 0;
    while (!file.eof()) {
        std::vector<T> inputs(inputs_num);
        for (int i = 0; i < inputs_num; ++i) {
            T t;
            file >> t;
            std::cout << t << ' ';
            inputs.push_back(t);
        }

        std::vector<T> outputs(outputs_num);
        for (int i = 0; i < outputs_num; ++i) {
            T t;
            file >> t;
            std::cout << t << ' ';
            outputs.push_back(t);
        }
        patterns_.push_back(std::make_pair(inputs, outputs));
    }
    return true;
}

template<typename T>
int PatternSet<T>::count() const
{
    return 0;
}

template<typename T>
auto PatternSet<T>::operator[](int i) const -> const Pattern&
{
    return patterns_.at(i);
}

template class PatternSet<int32_t>;
template class PatternSet<int64_t>;
template class PatternSet<float>;
template class PatternSet<double>;

} // namespace qlnet
