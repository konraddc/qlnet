#include "catch.hpp"

#include "node.h"

TEST_CASE( "NodeOutput", "[node]" ) {
    float value = 2.42f;
    qlnet::NodeOutput<float> node_output(value);
    CHECK( node_output == value );

    value = 1.56f;
    CHECK( node_output == value );

    qlnet::NodeInput<float> node_input = node_output;
    CHECK( node_input == node_output );

    float value_2 = 6.11f;
    node_output = value_2;
    CHECK( node_output == value_2 );
    CHECK( node_output != value );
    CHECK( node_input != value_2 );
}

TEST_CASE( "Node::update", "[node]" ) {
    std::vector<qlnet::NodeInput<float>> inputs;
    float f1 = 1.f, f2 = 2.f, f3 = 3.f;
    inputs.push_back(f1);
    inputs.push_back(f2);
    inputs.push_back(f3);

    qlnet::Node<float, qlnet::TransferFunc<float>::Identity> node;
    qlnet::NodeOutput<float> node_output = node.response();

    node.update();
    REQUIRE( node_output == 0.0f );

    node.connect(&inputs, 1);
    REQUIRE( node_output == 0.0f );

    node.update();
    REQUIRE( node_output == 6.f );
}
