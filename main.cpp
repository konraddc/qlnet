#include "patternset.h"

#include <iostream>

using namespace std;
using namespace qlnet;

int main(int argc, char** argv)
{
    PatternSet<int> *patterns = new PatternSet<int>();
    std::string input_file("sets/and2");
    if(!patterns->read(input_file))
        cout << "error: cannot read " << input_file << "\n";;

    cout << "Hello World!" << endl;
    return 0;
}
