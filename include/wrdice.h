#ifndef WR_DICE_H
#define WR_DICE_H


#include <stdint.h>
#include <stdbool.h>

struct BattleResult{
    float win_a;
    float win_b;
    float draw; 
    float death;
};

typedef struct {
    uint32_t    size;
    uint32_t    count[256];
    float       odds[256];
} Survived;

typedef struct{
    Survived stats_lnd[5];
    Survived stats_air[5];
    Survived stats_sea[5];
} Stats;

typedef struct{
    Stats army_a;
    Stats army_b;
} SimStats;

typedef struct{
    uint32_t stance_off[5];
    uint32_t stance_def[5];
} Stance;

typedef struct{
    uint32_t n_units_lnd[5];
    uint32_t n_units_air[5];
    uint32_t n_units_sea[5];
    Stance   stance_lnd;
    Stance   stance_air;
    Stance   stance_sea;
} Army;

typedef struct{
    uint32_t hp_stance_off[5];
    uint32_t hp_stance_def[5];
} HP;

typedef struct{
    HP lnd;
    HP air;
    HP sea;
} ArmyHP;


void run_simulation(const Army* restrict army_a, 
                    const Army* restrict army_b, 
                    SimStats*   restrict stats,
                    bool                 with_force_advantage,
                    bool                 with_batch_cap);
 

#endif