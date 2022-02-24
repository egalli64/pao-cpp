#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <climits>
#include <iostream>
#include "buggy_factorial.h"
#include "buggy_negator.h"

TEST_CASE("check vs require") {
    CHECK(0 == 1);
    REQUIRE(0 == 1);
    CHECK(0 == 2);
}

TEST_CASE("subcase") {
    std::cout << "Root level" << std::endl;

    SUBCASE("subcase 1") {
        std::cout << "Subcase 1" << std::endl;
    }

    SUBCASE("subcase 2") {
        std::cout << "Subcase 2" << std::endl;
    }
}
