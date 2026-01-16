
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include <SFML/Graphics.hpp>

class TransformHelper {
private:
    float width;
    float height;
    float padding;
    
public:
    TransformHelper(float w, float h, float pad = 20.f);
    
    sf::Vector2f normalizeToScreen(float x, float y) const;
    sf::Vector2f normalizeToScreen(const sf::Vector2f& normalized) const;
    
    sf::Vector2f screenToNormalize(float x, float y) const;
    
    void transformShape(sf::ConvexShape& shape) const;
    
    sf::FloatRect getCanvas() const;
};

#endif