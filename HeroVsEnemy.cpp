#define _CRT_SECURE_NO_WARNINGS
#include"HeroVsEnemy.h"
#include<iostream>
#include<ctime>

Hero::Hero(const char* name, int hp) {
    _nameSize = strlen(name);//•¶š”æ“¾
    _name = new char[_nameSize + 1];
    strcpy(_name, name);
    _hp = hp;
    _atk = 20;
    _def = 15;
}
Hero::~Hero() {

}
void Hero::atk(Enemy* enemy)
{
    int dmage = _atk - enemy->defGetter();
    int hp = enemy->hpGetter() - dmage;
    printf("%s‚ÌUŒ‚%d‚Ìƒ_ƒ[ƒW‚ğ—^‚¦‚½\n", _name, dmage);
    enemy->hpSetter(hp);
}
int Hero::hpGetter() { return _hp; }
int Hero::defGetter() { return _def; }
void Hero::hpSetter(int hp) { _hp = hp; }
void Hero::heal()
{
    int heal = (_def + _atk) / 2;
    int hp = _hp + heal;
    printf("%s‚Í%d‰ñ•œ‚µ‚½\n", _name, heal);
    hpSetter(hp);
}
void Hero::show() {
    printf("–¼‘O:%s\n‘Ì—Í:%d\nUŒ‚—Í:%d\n–hŒä—Í%d:\n", _name, _hp, _atk, _def);
}
const char* Hero::nameGetter() { return _name; }

//////Enemy/////


Enemy::Enemy(char* name, int hp) {
    _nameSize = strlen(name);//•¶š”æ“¾
    _name = new char[_nameSize + 1];
    strcpy(_name, name);
    _hp = hp;
    _atk = 18;
    _def = 12;
}

Enemy::~Enemy() {}
void Enemy::atk(Hero* hero)
{
    int dmage = _atk - hero->defGetter();
    int hp = hero->hpGetter() - dmage;
    printf("%s‚ÌUŒ‚%d‚Ìƒ_ƒ[ƒW‚ğ—^‚¦‚½\n", _name, dmage);
    hero->hpSetter(hp);
}
int Enemy::hpGetter() { return _hp; }
int Enemy::defGetter() { return _def; }
void Enemy::hpSetter(int hp) { _hp = hp; }
void Enemy::heal()
{
    int heal = (_def + _atk) / 2;
    int hp = _hp + heal;

    printf("%s‚Í%d‰ñ•œ‚µ‚½\n", _name, heal);
    hpSetter(hp);
}
void Enemy::show() {
    printf("–¼‘O:%s\n‘Ì—Í:%d\nUŒ‚—Í:%d\n–hŒä—Í:%d\n", _name, _hp, _atk, _def);
}
const char* Enemy::nameGetter() { return _name; }

