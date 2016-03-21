#include "patternset.h"
#include "node.h"

#include <iostream>

int main(int argc, char** argv)
{
//    float f1 = 1.f, f2 = 2.f, f3 = 3.f;
//    qlnet::NodeOutputRefs<float> inputs = { f1, f2, f3 };
//    qlnet::Node<float, qlnet::TransferFunc<float>::Linear> node;
//    qlnet::NodeOutputRef<float> node_output = node.output();
//    node.connect(inputs);
//    node.init_weights({ 1, 1, 1 });
//    node.update();

    qlnet::PatternSet<int> *patterns = new qlnet::PatternSet<int>();
    std::string input_file("sets/and2");
    if(!patterns->read(input_file))
        std::cout << "error: cannot read " << input_file << "\n";
    else
        std::cout << "patters#: " << patterns->size() << " inputs#: " << patterns->input_size() << " outputs#: " << patterns->output_size() << "\n";

    return 0;
}
