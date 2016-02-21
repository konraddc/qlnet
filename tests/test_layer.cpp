#include "catch.hpp"

#include "layer.h"
#include "node.h"
#include "nodeoutput.h"
#include "transferfunc.h"
#include "pattern.h"

TEST_CASE( "InputLayer", "[layer]" ) {
    qlnet::Pattern<float, int> pattern(3, 1);
    pattern.push_input(1.f);
    pattern.push_input(2.f);
    pattern.push_input(3.f);
    qlnet::InputLayer<qlnet::Pattern<float, int>::input_type> input_layer(pattern.input_size());

    input_layer.set_input(pattern.input());

    qlnet::Node<float, qlnet::TransferFunc<float>::Identity> node;
    qlnet::NodeOutput<float> node_output = node.response();
    node.connect(input_layer.outputs(), 1);
    node.update();

    REQUIRE( node_output == 6.f );
}
