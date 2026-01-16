#include "transform.h"
#include <stdexcept>

TransformHelper::TransformHelper(float w, float h, float pad) 
    : width(w), height(h), padding(pad) {
    if (width <= 2 * padding || height <= 2 * padding) {
        throw std::invalid_argument("Size too small for padding");
    }
}

sf::Vector2f TransformHelper::normalizeToScreen(float x, float y) const {
    // 从[-1, 1]转换到[padding, width-padding]
    float screenX = padding + (x + 1.0f) / 2.0f * (width - 2 * padding);
    float screenY = padding + (1.0f - y) / 2.0f * (height - 2 * padding);
    return sf::Vector2f(screenX, screenY);
}

sf::Vector2f TransformHelper::normalizeToScreen(const sf::Vector2f& normalized) const {
    return normalizeToScreen(normalized.x, normalized.y);
}

sf::Vector2f TransformHelper::screenToNormalize(float x, float y) const {
    float normX = ((x - padding) / (width - 2 * padding)) * 2.0f - 1.0f;
    float normY = 1.0f - ((y - padding) / (height - 2 * padding)) * 2.0f;
    return sf::Vector2f(normX, normY);
}

void TransformHelper::transformShape(sf::ConvexShape& shape) const {
    unsigned int pointCount = shape.getPointCount();
    
    // 创建转换后的顶点数组
    std::vector<sf::Vector2f> transformedPoints(pointCount);
    
    for (unsigned int i = 0; i < pointCount; ++i) {
        sf::Vector2f point = shape.getPoint(i);
        transformedPoints[i] = normalizeToScreen(point);
    }
    
    // 重新设置所有点
    for (unsigned int i = 0; i < pointCount; ++i) {
        shape.setPoint(i, transformedPoints[i]);
    }
}

sf::FloatRect TransformHelper::getCanvas() const {
    return sf::FloatRect(padding, padding, 
                        width - 2 * padding, 
                        height - 2 * padding);
}