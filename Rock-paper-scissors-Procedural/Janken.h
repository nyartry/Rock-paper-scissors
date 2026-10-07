#pragma once

enum class Hand
{
    Rock,
    Scissors,
    Paper
};

enum class JankenResult
{
    Draw,
    Player1Win,
    Player2Win
};

namespace Janken
{
    // 勝敗ルールはOOP固有ではないため、両方の版で同じ責務にする。
    JankenResult Judge(Hand player1, Hand player2);
}
