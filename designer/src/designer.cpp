
#include <SFML/Graphics.hpp>
#include <iostream>
#include "stroke.h"
#include "transform.h"

#define WIDTH (640)

void transformStrokeToScreen(strokeBase& stroke, float width, float height, float padding = 40.f) {
    sf::ConvexShape& shape = stroke.shape;
    unsigned int pointCount = shape.getPointCount();
    
    for (unsigned int i = 0; i < pointCount; ++i) {
        sf::Vector2f point = shape.getPoint(i);
        
        float screenX = padding + (point.x + 1.0f) / 2.0f * (width - 2 * padding);
        float screenY = padding + (1.0f - point.y) / 2.0f * (height - 2 * padding);
        
        shape.setPoint(i, sf::Vector2f(screenX, screenY));
    }
}

int main() {

    sf::RenderWindow window(sf::VideoMode(WIDTH, WIDTH), "MTD");
    window.setFramerateLimit(10);

    TransformHelper transformer(WIDTH, WIDTH, 0.f);
    
    strokeHeng st;
    st.startPos = sf::Vector2f(-0.7f, 0);
    st.t = 0.03f;
    st.s = 0.02f;
    st.l = 1.4f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        window.clear(sf::Color(0, 0, 0));

        st.generateShape();

        transformStrokeToScreen(st, WIDTH, WIDTH, 0.f);

        window.draw(st.shape);
        window.display();
    }

    return 0;
}