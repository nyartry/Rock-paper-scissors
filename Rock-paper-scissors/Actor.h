#pragma once
#include <string>
#include "Janken.h"
// 【OOP：抽象化】
// PlayerとEnemyに共通する状態と操作を「Actor」としてまとめる。
// SelectHand()が純粋仮想関数なので、Actorは直接生成できない抽象クラスになる。
class Actor
{
private:
    // 【OOP：カプセル化】
    // 状態をprivateにし、外部から勝手に書き換えられないようにする。
    std::string name;
    int hp;
    Hand hand;

public:
    Actor(const std::string& name);

    // Actor*を通してPlayerやEnemyを安全に破棄するための仮想デストラクタ。
    virtual ~Actor() = default;

    // 【OOP：テンプレートメソッド】
    // 処理の共通手順をActor側で決め、異なる部分だけを派生クラスに任せる。
    void Update();
    const std::string& GetName() const
    { return name;}
    Hand GetHand() const
    { return hand;}
    int GetHP() const
    { return hp; }
    void Damage();
    bool IsDead() const
    { return hp <= 0; }
protected:
    // 【OOP：ポリモーフィズムの差し替え箇所】
    // 手の選び方はActorごとに異なるため、派生クラスでの実装を必須にする。
    virtual void SelectHand() = 0;

    // 通常の仮想関数には共通の既定処理があり、必要な派生クラスだけ変更できる。
    virtual void OnDead();

    // handを直接protectedにせず、変更方法だけを派生クラスに公開する。
    void SetHand(Hand hand)
    {
        this->hand = hand;
    }
private:
    void ShowHand() const;
};
