#include "catch.hpp"

#include "layer.h"
#include "node.h"
#include "nodeoutput.h"
#include "transferfunc.h"
#include "pattern.h"

TEST_CASE( "InputLayer", "[layer]" ) {
    qlnet::Pattern<float, int> pattern({ 1.f, 2.f, 3.f }, { 1 });
    qlnet::InputLayer<qlnet::Pattern<float, int>::input_type> input_layer(pattern.input_size());

    input_layer.set_input(pattern.input());

    qlnet::Node<float, qlnet::TransferFunc<float>::Identity> node;
    qlnet::NodeOutputRef<float> node_output = node.output();
    node.connect(input_layer.output());
    node.init_weights({ 1, 1, 1 });

    node.update();
    REQUIRE( node_output == 6.f );
}

TEST_CASE( "Layer", "[layer]" ) {
    float f1 = 2.f, f2 = 3.f, f3 = 4.f;
    qlnet::NodeOutputRefs<float> output = { f1, f2, f3 };

    qlnet::Layer<float, qlnet::TransferFunc<float>::Identity> hidden_layer(2);
    hidden_layer.connect(output);
    for (auto &node : hidden_layer.nodes()) {
        node.init_weights({1, 1, 1});
    }
    hidden_layer.update();

    CHECK( hidden_layer.output().at(0) == 9.f );
    CHECK( hidden_layer.output().at(1) == 9.f );
}

TEST_CASE( "Layer connect", "[layer]") {
    qlnet::Pattern<float> pattern({ 1.f, 1.f, 1.f }, { 6.f, 6.f });
    auto *input_layer = new qlnet::InputLayer<float>(pattern.input_size());
    input_layer->set_input(pattern.input());
    auto *hidden_layer = new qlnet::Layer<float, qlnet::TransferFunc<float>::Identity>(2);
    hidden_layer->connect(input_layer->output());
    auto *output_layer = new qlnet::Layer<float, qlnet::TransferFunc<float>::Identity>(2);
    output_layer->connect(hidden_layer->output());

    hidden_layer->nodes().at(0).init_weights({ 1, 1, 1 });
    hidden_layer->nodes().at(1).init_weights({ 1, 1, 1 });
    hidden_layer->update();
    output_layer->nodes().at(0).init_weights({ 1, 1 });
    output_layer->nodes().at(1).init_weights({ 1, 1 });
    output_layer->update();

    CHECK(output_layer->output().at(0) == pattern.output_at(0));
    CHECK(output_layer->output().at(1) == pattern.output_at(1));
}
