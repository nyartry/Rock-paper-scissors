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
    // 【設計：責務の分離】
    // 勝敗ルールはPlayerやEnemyによって変わらないため、Actorから分離する。
    JankenResult Judge(Hand player1, Hand player2);
}
