#pragma once

#include "Actor.h"

// 【この版の構成：Player専用の処理】
// Playerはclassだが、手を選ぶ処理はPlayer自身のメンバー関数ではない。
// 呼び出す側がPlayer用の通常関数を選び、Actorを引数として渡す。
class Player : public Actor
{
public:
    Player();
};

void SelectPlayerHand(Actor& actor);
