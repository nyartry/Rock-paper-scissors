#include "Actor.h"
#include <iostream>
Actor::Actor(const std::string& name)
    : name(name),
    hp(3),
    hand(Hand::Rock)
{}
// 【OOP：テンプレートメソッド】
// 全Actorに共通する処理の順番を、基底クラスで一度だけ定義する。
void Actor::Update()
{
    // 仮想関数なので、実体がPlayerならPlayer::SelectHand()、
    // EnemyならEnemy::SelectHand()が呼ばれる。
    SelectHand();

    // 手を表示する処理は共通なので、Actorの実装を使う。
    ShowHand();
}
void Actor::ShowHand() const
{
    std::cout << name << " : ";
    switch (hand)
    {
    case Hand::Rock:
        std::cout << "グー";
        break;

    case Hand::Scissors:
        std::cout << "チョキ";
        break;

    case Hand::Paper:
        std::cout << "パー";
        break;
    }
    std::cout << "\n";
}

void Actor::OnDead()
{
    // 派生クラスが変更しない場合は、Actorの名前を使う共通処理になる。
    std::cout << name << "のHPが0になりました！\n";
}

void Actor::Damage()
{
    if (hp > 0)
    {
        --hp;

        if (IsDead())
        {
            // OnDead()も仮想関数なので、派生クラスが変更していれば
            // そのクラス固有の死亡処理が呼ばれる。
            OnDead();
        }
    }
}

