#include "chain_healing.h"

int main() {
    struct Player players[] = {
        {"Kara_Murat", 100, 500, 0},
        {"Koca_Yusuf", 400, 450, 0},
        {"Nasrettin_Hoca", 45, 400, 0},
        {"Cengiz_Han", 300, 600, 0}
    };
    int num_players = sizeof(players) / sizeof(players[0]);
    int start_power = 500;
    int jump_range = 1;
    float decay_factor = 0.25;

    chain_heal(start_power, jump_range, decay_factor, num_players, players);
	
	getchar();
	
	printf("Chain healing completed:\n");
		for (int i = 0; i < num_players; i++) {
			printf("%s's current PP: %d / Maximum PP: %d\n", players[i].name, players[i].current_pp, players[i].max_pp);
		}

    return 0;
}
