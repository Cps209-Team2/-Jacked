#ifndef PROJECTILE_H
#define PROJECTILE_H

class Projectile
{
    double x;
    double y;

    public:
    void fly();//ranged movable //hitbox
    void hit();//damages character
    Projectile();
};

#endif // PROJECTILE_H
