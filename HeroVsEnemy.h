#pragma once
const int maxName = 20;
class Enemy;
class Hero {
private:
    char* _name;
    int _nameSize;
private:
    int _hp;
    int _atk;
    int _def;
public:
    Hero(char* name, int hp);
    ~Hero();
    int hpGetter();
    int defGetter();
    void heal();
    void hpSetter(int hp);
    void atk(Enemy* enemy);
    void show();
};
class Enemy {
private:
    char* _name;
    int _nameSize;
private:
    int _hp;
    int _atk;
    int _def;
public:
    Enemy(char* name, int eHp);
    ~Enemy();
    int hpGetter();
    int defGetter();
    void hpSetter(int hp);
    void heal();
    void atk(Hero* hero);
    void show();
};
