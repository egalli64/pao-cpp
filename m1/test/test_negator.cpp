#include "doctest.h"

#include <climits>
#include "buggy_negator.h"

TEST_CASE("negator") {
    CHECK(negator(0) == 0);
    CHECK(negator(42) == -42);
    CHECK(negator(-63) == 63);
    CHECK(negator(INT_MIN) == INT_MAX);
}
