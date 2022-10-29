//
// Created by Niccolò Feresini on 13/10/22.
//

#include "game.h"

bool game::get_player1() const
{
    return player1;
}
bool game::get_player2() const
{
    return player2;
}
bool game::get_is_ended() const
{
    return is_ended;
}
void game::set_player1(bool validity)
{
    player1 = validity;
}
void game::set_player2(bool validity)
{
    player2 = validity;
}
void game::set_end_game(bool validity)
{
    is_ended = validity;
}

game::game():player1(false),player2(false),is_ended(false) {};

initialization game::startAuxiliarFunction() const
{
    initialization initial;
    pair<unsigned,unsigned > coord;
    std::cin>>coord.first;
    std::cout<<"y=";
    std::cin>>coord.second;
    std::cout<<"horizontal=0\nvertical=1\nselect orientation: ";
    std::cin>>initial.orientation;
    std::cout<<"select the length: ";
    std::cin>>initial.length;
    initial.coord = coord;
    return initial;
}

vector<vector<Ship>> game::start_game() const
{
    vector<vector<Ship>> allShip = {{},{}};
    initialization shipValue;
    bool has_valid_coordinate = false;
    for(size_t i = 0;i<2;++i)
    {
        initialization shipValue;
        do
        {
            std::cout<<std::endl<<"Player "<<(i+1)<<": insert the coordinates\nx=";
            shipValue = startAuxiliarFunction();
            has_valid_coordinate = Ship::has_valid_coordinate(shipValue.coord,shipValue.length,shipValue.orientation);
        }while(!has_valid_coordinate);
        allShip[i].push_back(Ship(shipValue.coord,shipValue.orientation,shipValue.length));
        int j = 0;
        while(j<(NUMBERSHIP-1))
        {
            has_valid_coordinate = false;
            initialization shipValue;
            std::cout<<std::endl<<"Player "<<(i+1)<<": insert the coordinates\nx=";
            shipValue = startAuxiliarFunction();
            has_valid_coordinate = Ship::has_valid_coordinate(shipValue.coord,shipValue.length,shipValue.orientation);
            if(!has_valid_coordinate) continue;

            Ship ship(shipValue.coord,shipValue.orientation,shipValue.length);
            for(const auto& playerShip:allShip[i])
            {
                if(playerShip.is_overlapping(ship))
                {
                    std::cout<<"Build Failed due to overlapping,please try again";
                    continue;
                }
            }
            allShip[i].push_back(ship);
            ++j;
        }
    }
    return allShip;
}

pair<unsigned,unsigned> game::player_shot(const std::string& name) const
{
    pair<unsigned int,unsigned int > coord;
    fflush(stdin);
    std::cout<<name<<" select the coordinates to shoot"<<std::endl<<"x=";
    std::cin>>coord.first;
    std::cout<<"y=";
    std::cin>>coord.second;
    std::cout<<std::endl;
    return coord;
}

bool game::has_hit(const pair<unsigned int,unsigned int>& coord,vector<Ship>& playerShips) const
{
    for(auto& ship : playerShips)
    {
        if(ship.update(coord))
        {
            std::cout<<"HIT";
            return true;
        }
    }
    return false;
}

bool game::is_dead(vector<Ship>& playerShips) const
{
    for(auto& ship : playerShips)
    {
       if(!ship.is_sunk()) return false;
    }
    return true;
}

void game::end_game(const std::string& player) const
{
   std::cout<<"\nCongratulation "<<player<<" is the winner";
}
