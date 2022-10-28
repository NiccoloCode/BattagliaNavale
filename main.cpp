/**
 * \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ BATTAGLIA NAVALE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 */
#include "game.h"
#include<string>
using std::string;

int main() {
    game battagliaNavale;
    bool has_hit;
    const string niccolo= "niccolo";
    const string luciano = "luciano";
    pair<unsigned ,unsigned > coord;

    auto allShip = battagliaNavale.start_game();

    while(true)
    {
        std::cout<<"Turn: "<<luciano<<std::endl;
        do
        {
         coord = battagliaNavale.player_shot(luciano);  // player 2 shoot
         has_hit = battagliaNavale.has_hit(coord,allShip[0]);
         if(battagliaNavale.is_dead(allShip[0]))
         {
             battagliaNavale.set_end_game(true);
             battagliaNavale.end_game(luciano);
             exit(0);
         }
         if(has_hit) std::cout<<"\nit is your turn again"<<std::endl;
        }while(has_hit);

        std::cout<<"Turn: "<<niccolo<<std::endl;
        do
        {
            coord = battagliaNavale.player_shot(niccolo);  // player 2 shoot
            has_hit = battagliaNavale.has_hit(coord,allShip[1]);
            if(battagliaNavale.is_dead(allShip[1]))
            {
                battagliaNavale.set_end_game(true);
                battagliaNavale.end_game(niccolo);
                exit(0);
            }
            if(has_hit) std::cout<<"\nit is your turn again"<<std::endl;
        }while(has_hit);
    }
}
