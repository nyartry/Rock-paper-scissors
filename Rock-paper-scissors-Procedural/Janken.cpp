#include "Janken.h"

JankenResult Janken::Judge(Hand player1, Hand player2)
{
    if (player1 == player2)
    {
        return JankenResult::Draw;
    }

    const bool player1Wins =
        (player1 == Hand::Rock && player2 == Hand::Scissors) ||
        (player1 == Hand::Scissors && player2 == Hand::Paper) ||
        (player1 == Hand::Paper && player2 == Hand::Rock);

    return player1Wins
        ? JankenResult::Player1Win
        : JankenResult::Player2Win;
}
