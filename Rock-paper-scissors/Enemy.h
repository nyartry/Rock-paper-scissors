#pragma once

#include "Actor.h"

// 【OOP：継承】
// EnemyもActorの一種なので、Playerと同じActorとして扱える。
class Enemy : public Actor
{
public:
    Enemy();

protected:
    // 【OOP：オーバーライド】
    // 同じSelectHand()という操作を、Enemyは乱数で選ぶ処理として実装する。
    void SelectHand() override;

    // OnDead()は必須ではないため、オーバーライドしなければActorの既定処理が使われる。
    //void OnDead() override;
};
