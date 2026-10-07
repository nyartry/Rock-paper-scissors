#pragma once

#include "Actor.h"

// 【OOP：継承】
// PlayerはActorの一種なので、Actorの共通状態と共通処理を引き継ぐ。
class Player : public Actor
{
public:
    Player();

protected:
    // 【OOP：オーバーライド】
    // Actorが要求する操作を、Player固有の「入力で選ぶ」処理として実装する。
    void SelectHand() override;

    // Actorの既定の死亡処理ではなく、Player固有の処理に差し替える。
    void OnDead() override;
};
