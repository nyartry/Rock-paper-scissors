#include "Enemy.h"

#include <cstdlib>
#include <iostream>

Enemy::Enemy()
    : Actor("Enemy")
{
}

void Enemy::SelectHand()
{
    // Enemyでは、乱数によって手を決める。
    // Playerと方法は違っても、外部からは同じSelectHand()として利用される。
    int randomHand = std::rand() % 3;

    SetHand(static_cast<Hand>(randomHand));
}
//ただの仮想関数の場合、あえてオーバーライドしないという選択もできる。
//void Enemy::OnDead()
//{
//    std::cout << "EnemyのHPが0になりました！\n";
//}
