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

TEST_CASE("No remaining cards")
{

    // playTurn should return an error when runing this function
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);

    for (int i = 0; i < 26; i++)
    {
        game.playTurn();
    }
    CHECK_THROWS(game.playTurn()); // check that a specific exception type is thrown - maybe i need to create custom exception for this problem
    CHECK_THROWS(game.playAll());  // check that a specific exception type is thrown - maybe i need to create custom exception for this problem
}

TEST_CASE("No one played yet")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    CHECK_THROWS(game.printLastTurn());
    CHECK(p1.cardesTaken() == "0");
    CHECK(p2.cardesTaken() == "0");
    CHECK(p1.stacksize() == "26");
    CHECK(p2.stacksize() == "26");

    std::stringstream output;
    std::streambuf *old_cout = std::cout.rdbuf(output.rdbuf());
    game.printLog();
    std::cout.rdbuf(old_cout);

    CHECK(output.str() == "");

    std::stringstream output1;
    std::streambuf *old_cout1 = std::cout.rdbuf(output1.rdbuf());
    game.printLog();
    std::cout.rdbuf(old_cout1);

    CHECK(output1.str() == "");
}

// Because playAl using playTurn for the remainig cards

TEST_CASE("Player cant play another game")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(Game(p1, p2));
    Player p3("Lilach");
    CHECK_THROWS(Game(p1, p3));
    Player p4("Mark");
    CHECK_THROWS(Game(p2, p4));
}

TEST_CASE("Sombody won")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    game.playAll();
    CHECK((p1.stacksize() == "0" || p2.stacksize() == "0"));
    CHECK(stoi(p2.cardesTaken()) + stoi(p2.cardesTaken()) == stoi("52"));

    std::stringstream output;
    std::streambuf *old_cout = std::cout.rdbuf(output.rdbuf());
    game.printWiner();
    std::cout.rdbuf(old_cout);

    if (p1.cardesTaken() > p2.cardesTaken())
    {
        CHECK(output.str() == p2.getName());
    }
    else if (p1.cardesTaken() == p2.cardesTaken())
    {
        CHECK(output.str() == p1.getName());
    }
    else
    {
        CHECK_THROWS(output.str());
    }
}

TEST_CASE("No remaining cards for war")
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    for (int i = 0; i < 25; i++)
    {
        game.playTurn();
    }

    int cardsTaken_p1 = stoi(p1.cardesTaken());
    int cardsTaken_p2 = stoi(p2.cardesTaken());
    int stackSize_p1 = stoi(p1.stacksize());
    int stackSize_p2 = stoi(p2.stacksize());
    int average = (stackSize_p1 + stackSize_p2) / 2;
    // Condition of War:
    CHECK_THROWS_AS(game.playTurn(), std::out_of_range);

    CHECK((p1.stacksize() == "0" || p2.stacksize() == "0"));
    CHECK(stoi(p2.cardesTaken()) == average + cardsTaken_p2);
    CHECK(stoi(p1.cardesTaken()) == average + cardsTaken_p1);

    std::stringstream output;
    std::streambuf *old_cout = std::cout.rdbuf(output.rdbuf());
    game.printWiner();
    std::cout.rdbuf(old_cout);

    if (p1.cardesTaken() > p2.cardesTaken())
    {
        CHECK(output.str() == p2.getName());
    }
    else if (p1.cardesTaken() == p2.cardesTaken())
    {
        CHECK_THROWS(output.str());
    }
    else
    {
        CHECK(output.str() == p1.getName());
    }
}