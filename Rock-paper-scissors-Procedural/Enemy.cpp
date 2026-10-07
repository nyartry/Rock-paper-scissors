#include "Enemy.h"

#include <cstdlib>

Enemy::Enemy()
    : Actor("Enemy")
{
}

void SelectEnemyHand(Actor& actor)
{
    actor.SetHand(static_cast<Hand>(std::rand() % 3));
}
