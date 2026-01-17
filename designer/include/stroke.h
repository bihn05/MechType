
#ifndef _STROKE_H_
#define _STROKE_H_

#include <SFML/Graphics.hpp>
#include "transform.h"

class strokeBase {
    public:
    int id;
    int type;
    sf::Vector2f startPos;
    float l;
    float t;
    float s;
    sf::ConvexShape shape;
    
    strokeBase();
    virtual ~strokeBase() = default;

    virtual void generateShape() = 0;
};

class strokeHeng : public strokeBase {
    public:
    void generateShape() override;
};

#endif