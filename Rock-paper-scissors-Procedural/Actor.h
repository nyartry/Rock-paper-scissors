#pragma once

#include <string>

#include "Janken.h"

// 【classや継承を使うことと、処理をオブジェクトに任せることは別】
// この版でもclassを使い、名前・HP・手を一つのActorにまとめている。
// PlayerとEnemyもActorを継承するが、Actorは手の選び方を持たず、
// ゲーム上の振る舞いを仮想関数で呼び分けることも行わない。
// どの処理をどのActorに適用するかは、呼び出す側が判断する。
class Actor
{
private:
    std::string name;
    int hp;
    Hand hand;

public:
    explicit Actor(const std::string& name);

    // Actor*に入れたPlayer／Enemyを安全にdeleteするために必要。
    // これは破棄の安全性のためで、手の選び方を切り替える仮想関数ではない。
    virtual ~Actor() = default;

    const std::string& GetName() const;
    int GetHP() const;
    Hand GetHand() const;

    void SetHP(int hp);
    void SetHand(Hand hand);
};

// Actorを受け取って処理する通常関数。
// 手の表示・ダメージなど、ゲームを進める処理は
// Actorのメンバーではなく、Actorの外側に置かれている。
bool IsDead(const Actor& actor);
void Damage(Actor& actor);
void ShowHand(const Actor& actor);
void ShowHP(const Actor& actor);
