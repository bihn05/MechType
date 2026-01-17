
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
        case 2:{ generateShapeUU(); break; }

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
    shape.setPoint(4, startPos+sf::Vector2f(l+t+s1*0.7f, -t-s1*0.7f));
    shape.setPoint(5, startPos+sf::Vector2f(l+t+s1, 0));
    shape.setPoint(6, startPos+sf::Vector2f(l, t+s1));
    shape.setPoint(7, startPos+sf::Vector2f(l, t));
    shape.setPoint(8, startPos+sf::Vector2f(l*0.5f, t*0.8f));
}
void stroke::generateShapeUU() {
    shape.setPointCount(9);
    shape.setFillColor(sf::Color::Red);
    shape.setPoint(0, startPos+sf::Vector2f(-t-s, +s));
    shape.setPoint(1, startPos+sf::Vector2f(-t, 0));
    shape.setPoint(2, startPos+sf::Vector2f(-t*0.9f, -l*0.5f));
    shape.setPoint(3, startPos+sf::Vector2f(-t, -l+s1*3.2f));
    shape.setPoint(4, startPos+sf::Vector2f(0.f,-l));
    shape.setPoint(5, startPos+sf::Vector2f(t*1.2f, -l+s1*5.f));
    shape.setPoint(6, startPos+sf::Vector2f(t*0.9f, -l*0.5f));
    shape.setPoint(7, startPos+sf::Vector2f(t+s,-t-s));
    shape.setPoint(8, startPos+sf::Vector2f(t+s*1.7f, -s));
}