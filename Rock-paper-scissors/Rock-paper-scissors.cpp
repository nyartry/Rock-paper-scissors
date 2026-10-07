#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "Janken.h"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// 【OOPの中心：抽象化とポリモーフィズム】
	// PlayerとEnemyは異なる具体的なオブジェクトだが、
	// どちらも「Actorとして行動できるもの」という共通の役割を持っている。
	// そのため、Actor*として同じ配列に入れ、同じ方法で扱うことができる。
	//
	// ここは「ゲームにどの具体的なActorを登場させるか」を決める場所である。
	// Actorを継承し、必要な仮想関数を実装した別のクラスに差し替えても、
	// 以降のゲームループは具体的な型を知らず、Actorの共通操作だけを呼べばよい。
	// 呼び出された後の具体的な振る舞いは、それぞれのオブジェクト自身が決める。
	//
	// 「何を登場させるか」と「どう利用するか」が分離されているため、
	// この生成部分を差し替えるだけで、ゲームループを変更せずに振る舞いを変更できる。
	// これが、オブジェクト指向による差し替え可能性の分かりやすい例である。
	Actor* actors[2] = { new Player(), new Enemy() };//{new Enemy(),new Enemy()}にしても対応可能。Enemy同士で勝手にじゃんけんする

	//Actor* actor = new Actor();//抽象クラスなので、Actor自身のインスタンス化はできない。Actorは抽象的な事をするのみに専念するよう制限をかけるという利点になる。


	while (!actors[0]->IsDead() && !actors[1]->IsDead())
	{
		std::cout << "\n--------------------\n";

		// 【OOP：ポリモーフィズム】
		// 呼び出す側はPlayerかEnemyかをif文で判定する必要がない。
		// 共通のUpdate()から、実体に応じたSelectHand()が自動的に呼び分けられる。
		for (int i = 0; i < 2; i++)
		{
			actors[i]->Update();
		}
		std::cout << "\n";

		// 【設計：責務の分離】
		// Actorは登場人物の状態と行動、Jankenはじゃんけんのルールを担当する。
		// OOPでも、すべての処理を一つのクラスに入れる必要はない。
		const JankenResult result = Janken::Judge(actors[0]->GetHand(),actors[1]->GetHand());
		switch (result)
		{
		case JankenResult::Draw:
			std::cout << "あいこ！\n";
			break;

		case JankenResult::Player1Win:
			std::cout << actors[0]->GetName() << "の勝ち！\n";
			actors[1]->Damage();
			break;

		case JankenResult::Player2Win:
			std::cout << actors[1]->GetName() << "の勝ち！\n";
			actors[0]->Damage();
			break;
		}
		for (int i = 0; i < 2; i++)
		{
			std::cout << actors[i]->GetName() << " HP : " << actors[i]->GetHP() << "\n";
		}
	}
	std::cout << "\nゲーム終了\n";

	// Actorのデストラクタがvirtualなので、Actor*からdeleteしても
	// 実際のPlayer／Enemyまで正しい順番で破棄される。
	for (int i = 0; i < 2; i++)
	{
		delete actors[i];
	}
}
