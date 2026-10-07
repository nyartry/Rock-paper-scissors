#include "Actor.h"

#include <iostream>

Actor::Actor(const std::string& name)
    : name(name),
      hp(3),
      hand(Hand::Rock)
{
}

const std::string& Actor::GetName() const
{
    return name;
}

int Actor::GetHP() const
{
    return hp;
}

Hand Actor::GetHand() const
{
    return hand;
}

void Actor::SetHP(int hp)
{
    this->hp = hp;

    if (this->hp < 0)
    {
        this->hp = 0;
    }
}

void Actor::SetHand(Hand hand)
{
    this->hand = hand;
}

bool IsDead(const Actor& actor)
{
    return actor.GetHP() <= 0;
}

void Damage(Actor& actor)
{
    // Actor自身がDamage()を持たないため、関数が外側からHPを変更する。
    if (!IsDead(actor))
    {
        actor.SetHP(actor.GetHP() - 1);

        if (IsDead(actor))
        {
            std::cout << actor.GetName() << "のHPが0になりました！\n";
        }
    }
}

void ShowHand(const Actor& actor)
{
    std::cout << actor.GetName() << " : ";

    switch (actor.GetHand())
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

void ShowHP(const Actor& actor)
{
    std::cout << actor.GetName() << " HP : " << actor.GetHP() << "\n";
}
