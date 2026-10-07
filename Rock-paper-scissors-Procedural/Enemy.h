#pragma once

#include "Actor.h"

// 【この版の構成：Enemy専用の処理】
// Enemyもclassだが、手を選ぶ処理はEnemy自身のメンバー関数ではない。
// 呼び出す側がEnemy用の通常関数を選び、Actorを引数として渡す。
class Enemy : public Actor
{
public:
    Enemy();
};

void SelectEnemyHand(Actor& actor);
