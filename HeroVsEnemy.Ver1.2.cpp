// HeroVsEnemy.Ver1.2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//


#include <iostream>
#include<ctime>
#include"HeroVsEnemy.h"
using namespace std;

void showStatus(const Hero hero, const Enemy enemy);

int main()
{
    int pHp = 0, eHp = 0;
    bool victory = false;
    int pMove = -1, eMove = 0, ePattern = 0;
    char pName[maxName] = " ";
    printf("名前を入力してください>");
    cin >> pName;
    printf("体力を入力しちゃってください>");
    cin >> pHp;
    char eName[maxName] = "ジャッキー・チョン";
    eHp = 120;
    Hero hero(pName, pHp);
    Enemy enemy(eName, eHp);

    while (victory == false) {
        void showStatus(const Hero  hero, const Enemy  enemy);//値渡しをしてヒーローとエネミーのステータス表示をする関数
       /* hero.show();
        enemy.show();*/
        while (pMove < 1 || pMove>2) {
            printf("1:攻撃\n2:回復\n");
            cin >> pMove;
        }
        switch (pMove) {
        case 1:hero.atk(&enemy);break;
        case 2:hero.heal();break;
        default:break;
        }
        pMove = -1;
        srand((unsigned int)time(NULL));
        if (enemy.hpGetter() <= eHp * 0.5) {
            ePattern = 2;
        }
        else {
            ePattern = 1;
        }

        eMove = rand() % ePattern;

        switch (eMove)
        {
        case 0:enemy.atk(&hero);break;
        case 1:enemy.heal();break;
        }
        if (hero.hpGetter() <= 0 || enemy.hpGetter() <= 0)
        {
            victory = true;
        }
    }
    cout << "戦闘終了" << endl;
}
void showStatus(const Hero hero,const Enemy enemy) 
{
    
    printf("名前:%s\n体力:%d\n防御力%d\n敵の名前:%s\n体力:%d\n防御力%d\n",hero.nameGetter(), hero.hpGetter(), hero.defGetter(), enemy.nameGetter(), enemy.hpGetter(), enemy.defGetter());

}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
