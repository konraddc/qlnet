#include "catch.hpp"

#include "patternset.h"

TEST_CASE( "PatternSet<int> \"and\"", "[patternset]" ) {
    qlnet::PatternSet<int> pattern_set;

    REQUIRE( pattern_set.size() == 0 );
    REQUIRE( pattern_set.read("../sets/and2") );

    CHECK( pattern_set.size() == 4 );

    REQUIRE( pattern_set[0].input_at(0) == 0);
    REQUIRE( pattern_set[0].input_at(1) == 0);
    REQUIRE( pattern_set[0].output_at(0) == 0);

    REQUIRE( pattern_set[1].input_at(0) == 0);
    REQUIRE( pattern_set[1].input_at(1) == 1);
    REQUIRE( pattern_set[1].output_at(0) == 0);

    REQUIRE( pattern_set[2].input_at(0) == 1);
    REQUIRE( pattern_set[2].input_at(1) == 0);
    REQUIRE( pattern_set[2].output_at(0) == 0);

    REQUIRE( pattern_set[3].input_at(0) == 1);
    REQUIRE( pattern_set[3].input_at(1) == 1);
    REQUIRE( pattern_set[3].output_at(0) == 1);
}

TEST_CASE( "PatternSet<int> \"or\"", "[patternset]" ) {
    qlnet::PatternSet<int> pattern_set;

    REQUIRE( pattern_set.size() == 0 );
    REQUIRE( pattern_set.read("../sets/or2") );

    CHECK( pattern_set.size() == 4 );

    REQUIRE( pattern_set[0].input_at(0) == 0);
    REQUIRE( pattern_set[0].input_at(1) == 0);
    REQUIRE( pattern_set[0].output_at(0) == 0);

    REQUIRE( pattern_set[1].input_at(0) == 0);
    REQUIRE( pattern_set[1].input_at(1) == 1);
    REQUIRE( pattern_set[1].output_at(0) == 1);

    REQUIRE( pattern_set[2].input_at(0) == 1);
    REQUIRE( pattern_set[2].input_at(1) == 0);
    REQUIRE( pattern_set[2].output_at(0) == 1);

    REQUIRE( pattern_set[3].input_at(0) == 1);
    REQUIRE( pattern_set[3].input_at(1) == 1);
    REQUIRE( pattern_set[3].output_at(0) == 1);
}

TEST_CASE( "PatternSet<int> \"xor\"", "[patternset]" ) {
    qlnet::PatternSet<int> pattern_set;

    REQUIRE( pattern_set.size() == 0 );
    REQUIRE( pattern_set.read("../sets/xor2") );

    CHECK( pattern_set.size() == 4 );

    REQUIRE( pattern_set[0].input_at(0) == 0);
    REQUIRE( pattern_set[0].input_at(1) == 0);
    REQUIRE( pattern_set[0].output_at(0) == 0);

    REQUIRE( pattern_set[1].input_at(0) == 0);
    REQUIRE( pattern_set[1].input_at(1) == 1);
    REQUIRE( pattern_set[1].output_at(0) == 1);

    REQUIRE( pattern_set[2].input_at(0) == 1);
    REQUIRE( pattern_set[2].input_at(1) == 0);
    REQUIRE( pattern_set[2].output_at(0) == 1);

    REQUIRE( pattern_set[3].input_at(0) == 1);
    REQUIRE( pattern_set[3].input_at(1) == 1);
    REQUIRE( pattern_set[3].output_at(0) == 0);
}
