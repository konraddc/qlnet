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
    qlnet::NodeOutputRef<float> node_output = node.output();
    node.connect(input_layer.outputs());
    node.init_weights({ 1, 1, 1 });

    node.update();
    REQUIRE( node_output == 6.f );
}

TEST_CASE( "Layer", "[layer]" ) {
    float f1 = 2.f, f2 = 3.f, f3 = 4.f;
    qlnet::NodeOutputRefs<float> outputs = { f1, f2, f3 };

    qlnet::Layer<float, qlnet::TransferFunc<float>::Identity> hidden_layer(2);
    hidden_layer.connect(outputs);
    for (auto &node : hidden_layer.nodes()) {
        node.init_weights({1, 1, 1});
    }
    hidden_layer.update();

    CHECK( hidden_layer.outputs().at(0) == 9.f );
    CHECK( hidden_layer.outputs().at(1) == 9.f );
}
