#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Actor.h"
#include "Enemy.h"
#include "Janken.h"
#include "Player.h"

// ============================================================
// 手続き型を中心にした構成例（class使用）
// ============================================================
// OOP版とファイルの役割を揃え、設計の違いを比較しやすくしている。
// この版でもActor、Player、Enemyの各クラスと継承を使っている。
// ただしPlayer／Enemy固有の処理は通常関数として外に置かれ、
// 呼び出す関数とその順番はmain()が決める。
// 一方、OOP版ではActorを共通の型として扱い、共通の操作を呼んだ後の
// 具体的な振る舞いをPlayer／Enemyオブジェクト自身に任せている。
//
// 両方でclassと継承を使うことにより、それらの有無ではなく、
// 「具体的な処理を呼び出す側とオブジェクトのどちらが選ぶか」を比較できる。
// この例では、ゲーム上の振る舞いを仮想関数で切り替えるかどうかが大きな違いになる。
// この版もカプセル化と継承というOO要素を含むため、純粋な手続き型ではない。
// 手続き型の進行を中心に、クラスを組み合わせたハイブリッド構成である。

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 実際に生成するオブジェクトはPlayerとEnemyだが、
    // どちらの変数も共通の型であるActor*として保持する。
    // ただしOOP版のように配列へまとめず、playerとenemyを別々に管理する。
    Actor* player = new Player();
    Actor* enemy = new Enemy();

    while (!IsDead(*player) && !IsDead(*enemy))
    {
        std::cout << "\n--------------------\n";

        // 【OOP版との中心的な対比】
        // OOP版では、actors[i]->Update()という同じ呼び出しで両者を扱える。
        // この版では、変数の型がどちらもActor*であっても、呼び出す側が
        // playerにはSelectPlayerHand、enemyにはSelectEnemyHandを選ぶ必要がある。
        // newで生成する実体の型だけを差し替えても、手の選び方は自動では変わらない。
        // つまり、具体的な処理の選択と実行順はmain()が受け持っている。
        SelectPlayerHand(*player);
        ShowHand(*player);

        SelectEnemyHand(*enemy);
        ShowHand(*enemy);

        std::cout << "\n";

        const JankenResult result = Janken::Judge(
            player->GetHand(),
            enemy->GetHand());

        switch (result)
        {
        case JankenResult::Draw:
            std::cout << "あいこ！\n";
            break;

        case JankenResult::Player1Win:
            std::cout << player->GetName() << "の勝ち！\n";
            Damage(*enemy);
            break;

        case JankenResult::Player2Win:
            std::cout << enemy->GetName() << "の勝ち！\n";
            Damage(*player);
            break;
        }

        ShowHP(*player);
        ShowHP(*enemy);
    }

    std::cout << "\nゲーム終了\n";

    delete player;
    delete enemy;

    return 0;
}
