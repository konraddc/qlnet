#include "catch.hpp"

#include "patternset.h"

TEST_CASE( "PatternSet<int> \"and\"", "[patternset]" ) {
    qlnet::PatternSet<int> pattern_set;

    REQUIRE( pattern_set.size() == 0 );
    CHECK( pattern_set.read("../sets/and2") );

    REQUIRE( pattern_set.size() == 4 );
    REQUIRE( pattern_set.input_size() == 2 );
    REQUIRE( pattern_set.output_size() == 1 );

    CHECK( pattern_set[0].input_at(0) == 0);
    CHECK( pattern_set[0].input_at(1) == 0);
    CHECK( pattern_set[0].output_at(0) == 0);

    CHECK( pattern_set[1].input_at(0) == 0);
    CHECK( pattern_set[1].input_at(1) == 1);
    CHECK( pattern_set[1].output_at(0) == 0);

    CHECK( pattern_set[2].input_at(0) == 1);
    CHECK( pattern_set[2].input_at(1) == 0);
    CHECK( pattern_set[2].output_at(0) == 0);

    CHECK( pattern_set[3].input_at(0) == 1);
    CHECK( pattern_set[3].input_at(1) == 1);
    CHECK( pattern_set[3].output_at(0) == 1);
}

TEST_CASE( "PatternSet<int> \"or\"", "[patternset]" ) {
    qlnet::PatternSet<int> pattern_set;

    REQUIRE( pattern_set.size() == 0 );
    CHECK( pattern_set.read("../sets/or2") );

    REQUIRE( pattern_set.size() == 4 );
    REQUIRE( pattern_set.input_size() == 2 );
    REQUIRE( pattern_set.output_size() == 1 );

    CHECK( pattern_set[0].input_at(0) == 0);
    CHECK( pattern_set[0].input_at(1) == 0);
    CHECK( pattern_set[0].output_at(0) == 0);

    CHECK( pattern_set[1].input_at(0) == 0);
    CHECK( pattern_set[1].input_at(1) == 1);
    CHECK( pattern_set[1].output_at(0) == 1);

    CHECK( pattern_set[2].input_at(0) == 1);
    CHECK( pattern_set[2].input_at(1) == 0);
    CHECK( pattern_set[2].output_at(0) == 1);

    CHECK( pattern_set[3].input_at(0) == 1);
    CHECK( pattern_set[3].input_at(1) == 1);
    CHECK( pattern_set[3].output_at(0) == 1);
}


TEST_CASE( "PatternSet<int> \"xor\"", "[patternset]" ) {
    qlnet::PatternSet<int> pattern_set;

    REQUIRE( pattern_set.size() == 0 );
    CHECK( pattern_set.read("../sets/xor2") );

    REQUIRE( pattern_set.size() == 4 );
    REQUIRE( pattern_set.input_size() == 2 );
    REQUIRE( pattern_set.output_size() == 1 );

    CHECK( pattern_set[0].input_at(0) == 0);
    CHECK( pattern_set[0].input_at(1) == 0);
    CHECK( pattern_set[0].output_at(0) == 0);

    CHECK( pattern_set[1].input_at(0) == 0);
    CHECK( pattern_set[1].input_at(1) == 1);
    CHECK( pattern_set[1].output_at(0) == 1);

    CHECK( pattern_set[2].input_at(0) == 1);
    CHECK( pattern_set[2].input_at(1) == 0);
    CHECK( pattern_set[2].output_at(0) == 1);

    CHECK( pattern_set[3].input_at(0) == 1);
    CHECK( pattern_set[3].input_at(1) == 1);
    CHECK( pattern_set[3].output_at(0) == 0);
}

TEST_CASE( "PatternSet<float> \"float_test\"", "[patternset]" ) {
    qlnet::PatternSet<float> pattern_set;

    REQUIRE( pattern_set.size() == 0 );
    CHECK( pattern_set.read("../sets/float_test") );

    REQUIRE( pattern_set.size() == 2 );
    REQUIRE( pattern_set.input_size() == 3 );
    REQUIRE( pattern_set.output_size() == 2 );

    // can also use Approx(-0123).epsilon(0.001) if needed;
    CHECK( pattern_set[0].input_at(0) ==  -0.123f);
    CHECK( pattern_set[0].input_at(1) ==   0.456f);
    CHECK( pattern_set[0].input_at(2) ==   0.789f);
    CHECK( pattern_set[0].output_at(0) ==  0.120f);
    CHECK( pattern_set[0].output_at(1) == -0.340f);

    CHECK( pattern_set[1].input_at(0) ==   1.123f);
    CHECK( pattern_set[1].input_at(1) ==  -2.456f);
    CHECK( pattern_set[1].input_at(2) ==   3.789f);
    CHECK( pattern_set[1].output_at(0) == -1.120f);
    CHECK( pattern_set[1].output_at(1) ==  2.340f);
}
