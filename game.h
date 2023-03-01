//
// Created by Niccolò Feresini on 13/10/22.
//

#ifndef BATTAGLIANAVALE_GAME_H
#define BATTAGLIANAVALE_GAME_H
#include "ship.h"
const unsigned NUMBERSHIP = 4;

struct initialization
{
    pair<unsigned,unsigned> coord;
    unsigned length;
    unsigned orientation;
};

class game {
    bool player1;
    bool player2;
    bool is_ended;
    initialization startAuxiliarFunction(void) const;
public:
    game(void);
    /**
     * getter and setter
     * @return
     */
    bool get_player1(void) const;
    bool get_player2(void) const;
    bool get_is_ended(void) const;
    void set_player1(bool);
    void set_player2(bool);
    void set_end_game(bool);

    /**
     * start to construct ships for each player
     * @return a vector of ship for both players
     */
    vector<vector<Ship>> start_game(void) const;

    pair<unsigned,unsigned> player_shot(const std::string& name) const;

    /**
     * check if there exists at least a ship that it is hit in coord and in this case update the boolean vector
     * @param coord
     * @param playerShips
     * @return true if a ship is hit and in this case the correspondent player must play again
     */
    bool has_hit(const pair<unsigned,unsigned>& coord,vector<Ship>& playerShips) const;

    /**
     * check if all the ships belong to player1/player2 are completely dead
     * @param playerShip
     * @return
     */
    bool is_dead(vector<Ship>& playerShip) const;

    /**
     * print the winning player
     * @param player
     */
    void end_game(const std::string& player) const;

};

#endif //BATTAGLIANAVALE_GAME_H
