#include "catch.hpp"

#include "patternset.h"

TEST_CASE( "Pattern<int> 0 inputs 0 output", "[pattern]" ) {
    qlnet::Pattern<int> pattern(0, 0);

    REQUIRE( pattern.input_size() == 0 );
    REQUIRE( pattern.output_size() == 0 );

    CHECK_FALSE( pattern.push_input(1) );
    CHECK_FALSE( pattern.push_output(1) );

    REQUIRE( pattern.input_size() == 0 );
    REQUIRE( pattern.output_size() == 0 );
}

TEST_CASE( "Pattern<int> 2 inputs 1 output", "[pattern]" ) {
    qlnet::Pattern<int> pattern(2, 1);

    REQUIRE( pattern.input_size() == 0 );
    REQUIRE( pattern.push_input(1) );
    CHECK( pattern.input_size() == 1 );
    REQUIRE( pattern.input_at(0) == 1 );

    REQUIRE( pattern.push_input(2) );
    CHECK( pattern.input_size() == 2 );
    REQUIRE( pattern.input_at(1) == 2 );

    REQUIRE_FALSE( pattern.push_input(3) );

    REQUIRE( pattern.output_size() == 0 );
    REQUIRE( pattern.push_output(1) );
    REQUIRE( pattern.output_size() == 1 );
    REQUIRE( pattern.output_at(0) == 1 );

    REQUIRE_FALSE( pattern.push_output(2) );
}

TEST_CASE( "Pattern<int> 3 inputs 2 output", "[pattern]" ) {
    const std::vector<int> input_data = { 1, 2, 3 };
    const std::vector<int> output_data = { 4, 5 };

    SECTION("move rvalue constructor") {
        qlnet::Pattern<int> pattern({ 1, 2, 3 }, { 4, 5 });
        REQUIRE( pattern.input() == input_data );
        REQUIRE( pattern.output() == output_data );
    }

    SECTION("move lvalue constructor") {
        std::vector<int> input = { 1, 2, 3 };
        std::vector<int> output = { 4, 5 };
        qlnet::Pattern<int> pattern(input, output);
        REQUIRE( pattern.input() == input_data );
        REQUIRE( pattern.output() == output_data );
        REQUIRE_FALSE( input == input_data );
        REQUIRE_FALSE( output == output_data );
    }

    SECTION("copy i/o constructor") {
        const std::vector<int> input = { 1, 2, 3 };
        const std::vector<int> output = { 4, 5 };
        qlnet::Pattern<int> pattern(input, output);
        REQUIRE( pattern.input() == input_data );
        REQUIRE( pattern.output() == output_data );
    }
}
