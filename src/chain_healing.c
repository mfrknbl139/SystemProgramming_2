#include <stdio.h>
#include "chain_healing.h"

void chain_heal(int start_power, int jump_range, float decay_factor, int num_players, struct Player players[]) {
    float current_power = start_power;

    for (int i = 0; i < num_players; i++) {
        if (!players[i].healed) {
            int heal_amount = calculate_heal(current_power, players[i]);
            players[i].current_pp += heal_amount;
            current_power *= (1 - decay_factor);
            
            if (players[i].current_pp > players[i].max_pp) {
                players[i].current_pp = players[i].max_pp;
            }
            
            players[i].healed = 1;
        }
    }

    printf("Chain healing completed:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s's current PP: %d / Maximum PP: %d\n", players[i].name, players[i].current_pp, players[i].max_pp);
    }
}

int calculate_heal(float current_power, struct Player player) {
    int max_increase = player.max_pp - player.current_pp;
    int heal_amount = (int)(current_power < max_increase ? current_power : max_increase);
    return heal_amount;
}
