/*
    Linked version
    g++ bt1.cpp -DBOOST_TEST_DYN_LINK -lboost_unit_test_framework
 */
#define BOOST_TEST_MODULE const_string test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(dummy) {
    BOOST_CHECK(1 + 1 == 2);
}
