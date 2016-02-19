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

TEST_CASE( "Node", "[node]" ) {
    std::vector<qlnet::NodeOutput<float>> outputs;

    auto act = [](float) -> float { return .0f; };
//    qlnet::Node<float, act> node;
}
