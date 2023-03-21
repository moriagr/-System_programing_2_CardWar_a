#include <iostream>
// #include <fstream>
// #include <sstream>
// #include <stdexcept>
using namespace std;

#include "../sources/player.hpp"
namespace ariel
{


    Player::Player(std::string n)
    {
        this->name = n;
    };

    string Player::stacksize()
    {
        return name;
    };
    string Player::cardesTaken()
    {
        return name;
    };
}