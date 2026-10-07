#include "Player.h"
#include <iostream>
#include <limits>

Player::Player()
    : Actor("Player")
{}

void Player::SelectHand()
{
    // Playerでは、プレイヤーからの入力によって手を決める。
    // この違いはPlayerの中に閉じているため、ゲームループは変更しなくてよい。
    int input;
    while (true)
    {
        std::cout << "\n手を選んでください\n";
        std::cout << "0 : グー\n";
        std::cout << "1 : チョキ\n";
        std::cout << "2 : パー\n";
        std::cout << "> ";

        std::cin >> input;

        if (std::cin &&
            input >= 0 &&
            input <= 2)
        {
            break;
        }

        std::cout << "0～2を入力してください。\n";
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n');
    }

    SetHand(static_cast<Hand>(input));
}

void Player::OnDead()
{
    std::cout << "PlayerのHPが0になりました！\n";
}
