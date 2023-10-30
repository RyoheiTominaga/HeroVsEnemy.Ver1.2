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
    Hero(const char* name, int hp);
    ~Hero();
    int hpGetter();
    int defGetter();
    void heal();
    void hpSetter(int hp);
    void atk(Enemy* enemy);
    void show();
    const char* nameGetter();
    Hero(const Hero& other)
    {
        _nameSize = other._nameSize;
        _name = new char[_nameSize + 1];
        strcpy(_name, other._name);
        _hp = other._hp;
        _atk = other._atk;
        _def = other._def;
    };//コピーコンストラクタ
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
    const char* nameGetter();
    Enemy(const Enemy& other)
    {
        _nameSize = other._nameSize;
        _name = new char[_nameSize + 1];
        strcpy(_name, other._name);
        _hp = other._hp;
        _atk = other._atk;
        _def = other._def;
    };//コピーコンストラクタ
};
