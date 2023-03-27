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
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);

    CHECK_THROWS(game.printLog());      // No one played yet so we can't   game.printLog(); prints all the turns played.
    CHECK_THROWS(game.printLastTurn()); // No one played yet so we can't print the log of the last turn.
    CHECK_THROWS(game.printWiner());    // No one played yet so there isn't any winner.
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
    CHECK((p1.stacksize() == 0 && p2.stacksize() == 0));
    CHECK(p2.cardesTaken() + p2.cardesTaken() == 52);

    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("No remaining cards for war") // Not sure
{
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    for (int i = 0; i < 25; i++)
    {
        game.playTurn();
    }

    int cardsTaken_p1 = p1.cardesTaken();
    int cardsTaken_p2 = p2.cardesTaken();
    int stackSize_p1 = p1.stacksize();
    int stackSize_p2 = p2.stacksize();
    int average = (stackSize_p1 + stackSize_p2) / 2;
    // Condition of War:
    CHECK_THROWS(game.playTurn());

    CHECK((p1.stacksize() == 0 && p2.stacksize() == 0));
    CHECK(p2.cardesTaken() == average + cardsTaken_p2);
    CHECK(p1.cardesTaken() == average + cardsTaken_p1);

    CHECK_NOTHROW(game.printWiner());
}