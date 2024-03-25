#ifndef CHAIN_HEALING_H
#define CHAIN_HEALING_H

struct Player {
    char name[50];
    int current_pp;
    int max_pp;
    int healed;
};

void chain_heal(int start_power, int jump_range, float decay_factor, int num_players, struct Player players[]);
int calculate_heal(float current_power, struct Player player);

#endif /* CHAIN_HEALING_H */
