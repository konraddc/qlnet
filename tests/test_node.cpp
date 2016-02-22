#include "catch.hpp"

#include "node.h"
#include "nodeoutput.h"
#include "transferfunc.h"

TEST_CASE( "NodeOutput", "[node]" ) {
    float value = 2.42f;
    qlnet::NodeOutputRef<float> node_output(value);
    CHECK( node_output == value );

    value = 1.56f;
    CHECK( node_output == value );

    qlnet::NodeOutputRef<float> node_output2 = node_output;
    CHECK( node_output2 == node_output );

    float value_2 = 6.11f;
    node_output = value_2;
    CHECK( node_output == value_2 );
    CHECK( node_output != value );
    CHECK( node_output2 != value_2 );
}

TEST_CASE( "Node", "[node]" ) {
    std::vector<qlnet::NodeOutputRef<float>> inputs;
    float f1 = 1.f, f2 = 2.f, f3 = 3.f;
    inputs.push_back(f1);
    inputs.push_back(f2);
    inputs.push_back(f3);

    qlnet::Node<float, qlnet::TransferFunc<float>::Linear> node;
    qlnet::NodeOutputRef<float> node_output = node.output();

    node.update();
    REQUIRE( node_output == 0.0f );

    node.connect(inputs, 1);
    REQUIRE( node_output == 0.0f );

    node.update();
    REQUIRE( node_output == 6.f );
}

TEST_CASE( "InputNode", "[node]" ) {
    qlnet::InputNode<float> input_node;
    qlnet::NodeOutputRef<float> node_output = input_node.output();
    CHECK( node_output == 0 );

    input_node.set_output(3.23f);
    REQUIRE( node_output == 3.23f );

    input_node.set_output(1.5f);
    REQUIRE( node_output == 1.5f );
}
