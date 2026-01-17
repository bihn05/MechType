
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "stroke.h"
#include "transform.h"

#define WIDTH (200)

void transformStrokeToScreen(sf::ConvexShape& out, sf::ConvexShape& shape, float width, float height, float padding = 40.f) {
    unsigned int pointCount = shape.getPointCount();
    out.setFillColor(shape.getFillColor());
    out.setPointCount(pointCount);
    
    for (unsigned int i = 0; i < pointCount; ++i) {
        sf::Vector2f point = shape.getPoint(i);
        
        float screenX = padding + (point.x + 1.0f) / 2.0f * width;
        float screenY = padding + (1.0f - point.y) / 2.0f * height;
        
        out.setPoint(i, sf::Vector2f(screenX, screenY));
    }
}

int main() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, WIDTH), "MTD");
    window.setFramerateLimit(10);

    sf::ConvexShape displayShape;

    TransformHelper transformer(WIDTH, WIDTH, 0.f);
    
    stroke st;
    std::vector<stroke> zi;

    st.startPos = sf::Vector2f(-0.7f, 0.2f);
    st.type = STROKE_HENG;
    st.t = 0.03f;
    st.s = 0.04f;
    st.s1 = 0.04f;
    st.l = 1.4f;
    zi.push_back(st);

    st.startPos = sf::Vector2f(0.f, 0.7f);
    st.type = STROKE_SHU;
    st.t = 0.07f;
    st.s = 0.04f;
    st.s1 = 0.04f;
    st.l = 1.4f;
    zi.push_back(st);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color(0, 0, 0));

        for (stroke prst : zi) {
            prst.generateShape();
            transformStrokeToScreen(displayShape, prst.shape, WIDTH, WIDTH, 0.f);
            window.draw(displayShape);
        }

        window.display();
    }

    return 0;
}