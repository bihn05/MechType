
#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>

typedef struct {
    glm::vec2 coord;
    float meta;
} StrokePoint;

class strokeBase {
    public:
    glm::vec2 startPos;
    float length;
    float width;
    std::vector<StrokePoint> generatePathPoints();
    private:
};

#endif