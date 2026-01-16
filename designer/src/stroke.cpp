
#include "stroke.h"

strokeBase::strokeBase() {
    startPos = sf::Vector2f(0.f, 0.f);
    length = 0.f;
    thick = 0.f;
    style = 0.f;
    id = 0;
    type = 0;
    shape.setPointCount(2);
    shape.setFillColor(sf::Color::White);
}

void strokeHeng::generateShape() {
    shape.setFillColor(sf::Color::Green);
    shape.setPointCount(4);
    shape.setPoint(0, startPos+sf::Vector2f(-thick, thick));
    shape.setPoint(1, startPos+sf::Vector2f(-thick, -thick));
    shape.setPoint(2, startPos+sf::Vector2f(thick+length, -thick));
    shape.setPoint(3, startPos+sf::Vector2f(thick+length, thick));
}