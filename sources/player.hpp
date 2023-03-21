#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


namespace ariel
{

    class Player
    {
    private:
        int score;
        string name;

    public:
        Player(std::string n);
        Player();

        string stacksize();
        string cardesTaken();
    };
}
#endif