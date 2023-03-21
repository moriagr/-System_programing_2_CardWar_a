#include "doctest.h"
#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"
using namespace ariel;


#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

TEST_CASE("Factorials of small numbers") {
    CHECK(playTurn() == 1);
    CHECK(playTurn() == 1);
    CHECK(playTurn() == 2);
    CHECK(playTurn() == 6);


}
        void printLastTurn();
        void playAll();    // playes the game untill the end
        void printWiner(); // prints the name of the winning player
        void printLog();   // prints all the turns played one line per turn (same format as void printLastTurn())
        void printStats

TEST_CASE("Factorials of large numbers") {
    CHECK(factorial(4) == 24);
    CHECK(factorial(6) == 720);
    CHECK(factorial(10) == 3628800);

    // auto f3 = factorial(3);
    // CHECK((f3==5 || f3==6)); // logic OR requires parentheses!
}


TEST_CASE("Factorials of negative numbers") { 
    CHECK_THROWS(factorial(-1));  // check that some exception is thrown
    CHECK_THROWS_AS(factorial(-2), std::out_of_range);  // check that a specific exception type is thrown
    CHECK_THROWS_AS(factorial(-2), std::exception);  // check that a specific exception type (or a descendant) is thrown
}