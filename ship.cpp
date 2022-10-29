//
// Created by Niccolò Feresini on 13/10/22.
//

#include "ship.h"

Ship::Ship(pair<unsigned int, unsigned int>& coord, unsigned int orientation, unsigned int length) : booleanCoordinates(length,true),isAlive(true)
{
    enum orient{horizontal = 0,vertical = 1};
    if(orientation == horizontal)//horizontal
    {
        for(size_t i = 0;i<length;++i && ++coord.second)
        {
            coordinates.push_back(coord);
        }
    }
    else
    {
        for(size_t i = 0;i<length;++i && ++coord.first)
        {
            coordinates.push_back(coord);
        }
    }
}

vector<pair<unsigned,unsigned>> Ship::get_coordinates() const
{
    return coordinates;
}

vector<bool> Ship::get_boolean_coordinates() const
{
    return booleanCoordinates;
}

bool Ship::has_valid_coordinate(const pair<unsigned,unsigned>& coord,unsigned length,unsigned orientation)
{
    enum orient{horizontal = 0, vertical = 1};
    if(coord>9 || coord<0)
    {
        std::cout<<"coordinates not valid"<<std::endl;
        return false;
    }
    if(orientation==horizontal)
    {
        if(coord.second+length>10)
        {
            std::cout<<"coordinates not valid"<<std::endl;
            return false;
        }
    }else
    {
        if(coord.first+length>10)
        {
            std::cout<<"coordinates not valid"<<std::endl;
            return false;
        }
    }
    return true;
}

bool operator>(const pair<unsigned,unsigned>& coord,unsigned x)
{
    if(coord.first>x && coord.second>x) return true;
    return false;
}

bool operator<(const pair<unsigned,unsigned>& coord,unsigned x)
{
    if(coord.first<x && coord.second<x) return true;
    return false;
}

bool operator==(const pair<unsigned,unsigned>& coord1,const pair<unsigned,unsigned>& coord2)
{
    if(coord1.first == coord2.first && coord1.second == coord2.second) return true;
    return false;
}

bool Ship::is_overlapping(const Ship& nave2)  const
{
    for(const auto& coordNave1 :coordinates)
    {
        for(const auto& coordNave2 :nave2.coordinates)
        {
            if(coordNave1 == coordNave2)
            {
                return true;
            }
        }
    }
    return false;
}

bool Ship::update(const pair<unsigned,unsigned>& coord)
{
    for(size_t i = 0;i<coordinates.size();++i)
    {
        if(coord == coordinates[i])
        {
            booleanCoordinates[i] = false;
            return true;
        }
    }
    return false;
}

bool Ship::is_sunk()
{
    for (const auto &isAlive: booleanCoordinates)
    {
        if(isAlive == true) return false;
    }
    this->isAlive = false;
    return true;
}
