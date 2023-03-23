#include <iostream>
// #include <fstream>
// #include <sstream>
// #include <stdexcept>
using namespace std;

#include "player.hpp"
namespace ariel
{

    Player::Player(std::string n)
    {
        this->name = n;
    };

    string Player::stacksize()
    {
        return "26";
    };
    string Player::cardesTaken()
    {
        return "0";
    };
    string Player::getName()
    {
        return name;
    }
}