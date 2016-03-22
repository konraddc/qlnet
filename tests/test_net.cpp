#include "catch.hpp"

#include "net.h"
#include "pattern.h"
#include "patternset.h"
#include "layer.h"
#include "transferfunc.h"

TEST_CASE( "Net_and", "[net]" ) {
    qlnet::PatternSet<float> pattern_set;
    REQUIRE( pattern_set.read("../sets/and2") );

    qlnet::InputLayer<qlnet::Pattern<float>::input_type> input_layer(pattern_set.input_size());
    qlnet::HiddenLayer<float, qlnet::TransferFunc<float>::UnipolarStep> output_layer(1);

    output_layer.nodes().at(0).init_weights({ 0.5f, 0.5f });

    qlnet::Net<float> net;
    net.set_input_layer(&input_layer);
    net.add_hidden_layer(&output_layer);

    SECTION("0 and 0") {
        std::vector<float> result = net.evaluate(pattern_set[0].input());
        REQUIRE (result == pattern_set[0].output() );
    }

    SECTION("0 and 1") {
        std::vector<float> result = net.evaluate(pattern_set[1].input());
        REQUIRE (result == pattern_set[1].output() );
    }

    SECTION("1 and 0") {
        std::vector<float> result = net.evaluate(pattern_set[2].input());
        REQUIRE (result == pattern_set[2].output() );
    }

    SECTION("1 and 1") {
        std::vector<float> result = net.evaluate(pattern_set[3].input());
        REQUIRE (result == pattern_set[3].output() );
    }
}

TEST_CASE( "Net_or", "[net]" ) {
    qlnet::PatternSet<float> pattern_set;
    REQUIRE( pattern_set.read("../sets/or2") );

    qlnet::Net<float> net;
    qlnet::InputLayer<qlnet::Pattern<float>::input_type> input_layer(pattern_set.input_size());
    net.set_input_layer(&input_layer);

    qlnet::HiddenLayer<float, qlnet::TransferFunc<float>::UnipolarStep> output_layer(1);
    output_layer.nodes().at(0).init_weights({ 1.f, 1.f });
    net.add_hidden_layer(&output_layer);

    SECTION("0 or 0") {
        std::vector<float> result = net.evaluate(pattern_set[0].input());
        REQUIRE (result == pattern_set[0].output() );
    }

    SECTION("0 or 1") {
        std::vector<float> result = net.evaluate(pattern_set[1].input());
        REQUIRE (result == pattern_set[1].output() );
    }

    SECTION("1 or 0") {
        std::vector<float> result = net.evaluate(pattern_set[2].input());
        REQUIRE (result == pattern_set[2].output() );
    }

    SECTION("1 or 1") {
        std::vector<float> result = net.evaluate(pattern_set[3].input());
        REQUIRE (result == pattern_set[3].output() );
    }
}

TEST_CASE( "Net_xor", "[net]" ) {
    qlnet::PatternSet<float> pattern_set;
    REQUIRE( pattern_set.read("../sets/xor2") );

    qlnet::Net<float> net;
    qlnet::InputLayer<qlnet::Pattern<float>::input_type> input_layer(pattern_set.input_size());
    net.set_input_layer(&input_layer);

    qlnet::HiddenLayer<float, qlnet::TransferFunc<float>::UnipolarStep> hidden_layer(2);
    hidden_layer.nodes().at(0).init_weights({ 0.5f, 0.5f });
    hidden_layer.nodes().at(1).init_weights({ 1.f, 1.f });
    net.add_hidden_layer(&hidden_layer);

    qlnet::HiddenLayer<float, qlnet::TransferFunc<float, 1, 10>::UnipolarStep> output_layer(1);
    output_layer.nodes().at(0).init_weights({ -1.f, 1.f });
    net.add_hidden_layer(&output_layer);

    SECTION("0 xor 0") {
        std::vector<float> result = net.evaluate(pattern_set[0].input());
        REQUIRE (result == pattern_set[0].output() );
    }

    SECTION("0 xor 1") {
        std::vector<float> result = net.evaluate(pattern_set[1].input());
        REQUIRE (result == pattern_set[1].output() );
    }

    SECTION("1 xor 0") {
        std::vector<float> result = net.evaluate(pattern_set[2].input());
        REQUIRE (result == pattern_set[2].output() );
    }

    SECTION("1 xor 1") {
        std::vector<float> result = net.evaluate(pattern_set[3].input());
        REQUIRE (result == pattern_set[3].output() );
    }
}
