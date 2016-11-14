#ifndef ENTITY_H
#define ENTITY_H
#include <QDebug>
#include <QPoint>
#include <QRect>
#include <QSize>
#include <QFile>
#include "accesslabel.h"
#include "weapon.h"

class Entity
{
protected:
    QPoint pos;
    QRect *body;
    int HP;
    bool left;
    bool right;
    int id;
    bool hit;
    int hitCount;
    AccessLabel *label;


public:
    Entity();
    Entity(int x, int y){ pos.setX(x); pos.setY(y); }

    // observer method implemented so object can hide label when destroyed
    virtual void setLabel(AccessLabel *lbl) { label = lbl; }
    virtual void hideLabel() { label->hideLabel(); }

    //IDENTIFICATION
    virtual int getId() { return id; }
    virtual bool isPlayer() { return false; }
    virtual bool isEnemy() { return false; }

    //POSITION
    // position setters and getters
    virtual QPoint getPos() { return pos; }
    virtual void setX(int x) { pos.setX(x); }
    virtual void setY(int y) { pos.setY(y); }
    int getX() { return pos.x(); }
    int getY() { return pos.y(); }
    virtual void moveLeft() { }
    virtual void moveRight() { }

    //DIRECTION
    // direction controls
    virtual void faceRight() { right = true; left = false; }
    virtual void faceLeft() { left = true; right = false; }
    virtual bool facingRight() { return right; }
    virtual bool facingLeft() { return left; }

    //DAMAGE
    // functions to check and change status of whether or not the entity is damaged by a weapon
    virtual void setHit(bool smack) { hit = smack; }
    virtual bool isHit() { return hit; }
    virtual void resetHitCount() { hitCount = 0; }
    virtual int getHitCount() { return hitCount; }
    virtual void countHit() { hitCount++; }

    //HITBOX
    // getters and setters for Entity "hitbox", which is used for collision detection
    virtual QSize getSize() { return body->size(); }
    virtual QRect getBody() { return *body; }
    virtual void setBody(QRect *temp) { body = temp; }

    //HP
    // getters and setters for Entity health points
    virtual void takeDmg(int x) { HP -= x; }
    virtual int getDmg() = 0;
    virtual int getHP() { return HP; }
    virtual void setHP(int health) { HP = health; }
    virtual Weapon* getWeapon() = 0;

    //SAVE/LOAD
    // savaes current position, health, and weapons of specific entity
    virtual void saveState (QFile *file) = 0;

    virtual ~Entity() { delete body; }
};

#endif // ENTITY_H
