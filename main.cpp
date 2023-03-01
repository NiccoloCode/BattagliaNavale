/**
 * \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ BATTAGLIA NAVALE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 */
#include "game.h"
#include<string>
using std::string;

int main() {
    int x;
    game battagliaNavale;
    bool has_hit;
    const string first_player_name= "niccolo";
    const string second_player_name= "luciano";
    pair<unsigned ,unsigned > coord;

    auto allShip = battagliaNavale.start_game();

    while(true)
    {
        std::cout<<"Turn: "<<second_player_name<<std::endl;
        do
        {
         coord = battagliaNavale.player_shot(second_player_name);  // player 2 shoot
         has_hit = battagliaNavale.has_hit(coord,allShip[0]);
         if(battagliaNavale.is_dead(allShip[0]))
         {
             battagliaNavale.set_end_game(true);
             battagliaNavale.end_game(second_player_name);
             exit(0);
         }
         if(has_hit) std::cout<<"\nit is your turn again"<<std::endl;
        }while(has_hit);

        std::cout<<"Turn: "<<first_player_name<<std::endl;
        do
        {
            coord = battagliaNavale.player_shot(first_player_name);  // player 2 shoot
            has_hit = battagliaNavale.has_hit(coord,allShip[1]);
            if(battagliaNavale.is_dead(allShip[1]))
            {
                battagliaNavale.set_end_game(true);
                battagliaNavale.end_game(first_player_name);
                exit(0);
            }
            if(has_hit) std::cout<<"\nit is your turn again"<<std::endl;
        }while(has_hit);
    }
}
