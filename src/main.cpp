#include "patternset.h"

#include <iostream>

int main(int argc, char** argv)
{
    qlnet::PatternSet<int> *patterns = new qlnet::PatternSet<int>();
    std::string input_file("sets/and2");
    if(!patterns->read(input_file))
        std::cout << "error: cannot read " << input_file << "\n";
    else
        std::cout << "patters#: " << patterns->size() << " inputs#: " << patterns->input_size() << " outputs#: " << patterns->output_size() << "\n";

    return 0;
}
