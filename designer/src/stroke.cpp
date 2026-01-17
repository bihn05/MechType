
#include "stroke.h"
#include <iostream>

stroke::stroke() {
    startPos = sf::Vector2f(0.f, 0.f);
    offset = sf::Vector2f(0.f, 0.f);
    l = 0.f;
    t = 0.f;
    s = 0.f;
    id = 0;
    type = 0;
    shape.setPointCount(2);
    shape.setFillColor(sf::Color::White);
}
stroke::~stroke() {
    ;
}

void stroke::generateShape() {
    switch (type) {
        case 1:{ generateShapeHG(); break; }
        default:;
    }
}
void stroke::generateShapeHG() {
    shape.setPointCount(9);
    shape.setFillColor(sf::Color::Green);
    shape.setPoint(0, startPos+sf::Vector2f(-t-s*0.9f, t+s*0.7f));
    shape.setPoint(1, startPos+sf::Vector2f(0, -t-s*0.7f));
    shape.setPoint(2, startPos+sf::Vector2f(l*0.5f, -t*0.8f));
    shape.setPoint(3, startPos+sf::Vector2f(l, -t));
    shape.setPoint(4, startPos+sf::Vector2f(l+t+s*0.7f, -t-s*0.7f));
    shape.setPoint(5, startPos+sf::Vector2f(l+t+s, 0));
    shape.setPoint(6, startPos+sf::Vector2f(l, t+s));
    shape.setPoint(7, startPos+sf::Vector2f(l, t));
    shape.setPoint(8, startPos+sf::Vector2f(l*0.5f, t*0.8f));

}