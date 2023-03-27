#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "game.hpp"
#include "player.hpp"

namespace ariel
{
    Game::Game(Player p1_, Player p2_) : p1(p1_), p2(p2_)
    {
    }
    void Game::playTurn()
    {
    }
    void Game::printLastTurn()
    {
    }
    void Game::playAll()
    {

    } // playes the game untill the end
    void Game::printWiner()
    {

    } // prints the name of the winning player
    void Game::printLog()
    {

    } // prints all the turns played one line per turn (same format as void printLastTurn())
    void Game::printStats()
    {
    }

        Player Game::getP1()
    {
        return p1;
    }
        Player Game::getP2()
    {
        return p2;
    }
}