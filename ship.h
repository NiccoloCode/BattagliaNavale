//
// Created by Niccolò Feresini on 13/10/22.
//

#ifndef BATTAGLIANAVALE_SHIP_H
#define BATTAGLIANAVALE_SHIP_H
#include <iostream>
#include <vector>
using std::vector;
using std::pair;

class Ship
{
    bool isAlive;
    vector<pair<unsigned,unsigned>> coordinates;
    vector<bool> booleanCoordinates; // (x,y) = FALSE if the ship is hit in this coordinate
public:
    /**
     *
     * @param coord represents the initial point to build the ship
     * @param orientation = 0 is equal to horizontal
     * @param length represents the length of the ship
     */
    Ship(pair<unsigned,unsigned>& coord,unsigned orientation,unsigned length);
    virtual ~Ship() = default;
    vector<pair<unsigned,unsigned>> get_coordinates() const;
    vector<bool> get_boolean_coordinates() const;

    /**
     * check if nave2 could be built or there is an overlapping
     * @param nave2
     * @return
     */
    bool is_overlapping(const Ship& nave2)  const;

    /**
     * check if the ship is hit and in this case update che boolean vector
     * @param coord
     * @return
     */
    bool update(const pair<unsigned,unsigned>& coord);
    /**
     * check if the ship is sunk
     * @return
     */
    bool is_sunk();

    /**
     * check if the coordinates given are valid
     * @param coord
     * @param length
     * @param orientation
     * @return
     */
    static bool has_valid_coordinate(const pair<unsigned,unsigned>& coord,unsigned length,unsigned orientation);

};

bool operator>(const pair<unsigned,unsigned>& coord,unsigned x);
bool operator<(const pair<unsigned,unsigned>& coord,unsigned x);
bool operator==(const pair<unsigned,unsigned>& coord1,const pair<unsigned,unsigned>& coord2);

#endif //BATTAGLIANAVALE_SHIP_H
