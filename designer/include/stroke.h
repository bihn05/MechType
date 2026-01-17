
#ifndef _STROKE_H_
#define _STROKE_H_

#include <SFML/Graphics.hpp>
#include "transform.h"

#define STROKE_NONE     0
#define STROKE_HENG     1
#define STROKE_SHU      2

class stroke {
    public:
    int id;
    int type;
    sf::Vector2f startPos;
    sf::Vector2f offset;
    float l;
    float t;
    float s;
    float s1;
    sf::ConvexShape shape;
    
    stroke();
    ~stroke();

    void generateShape();

    protected:
    void generateShapeHG();
    void generateShapeUU();
    void generateShapePX();
    void generateShapeNA();
    void generateShapeTI();
    void generateShapeDM();
};

#endif