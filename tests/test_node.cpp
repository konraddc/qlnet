#include "catch.hpp"

#include "node.h"
#include "nodeoutput.h"
#include "transferfunc.h"

TEST_CASE( "Node init", "[node]" ) {
    float f1 = 1.f, f2 = 2.f, f3 = 3.f;
    qlnet::NodeOutputRefs<float> inputs = { f1, f2, f3 };

    {
        qlnet::Node<float, qlnet::TransferFunc<float>::Linear> node;
        qlnet::NodeOutputRef<float> node_output = node.output();
        node.connect(inputs);
        node.init_weights({1, 2, 3});
        node.update();
        REQUIRE( node_output == 14.f );
    }

    {
        qlnet::Node<float, qlnet::TransferFunc<float>::Linear> node({ 3, 2, 1 });
        qlnet::NodeOutputRef<float> node_output = node.output();
        node.connect(inputs);
        node.update();
        REQUIRE( node_output == 10.f );
    }
}

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
    float f1 = 1.f, f2 = 2.f, f3 = 3.f;
    qlnet::NodeOutputRefs<float> inputs = { f1, f2, f3 };

    qlnet::Node<float, qlnet::TransferFunc<float>::Linear> node;
    qlnet::NodeOutputRef<float> node_output = node.output();

    node.update();
    REQUIRE( node_output == 0.0f );

    node.connect(inputs);
    node.init_weights({ 1, 1, 1 });
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
