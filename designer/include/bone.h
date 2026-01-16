
#ifndef _BONE_H_
#define _BONE_H_

#include "shader.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

void drawBone(Shader &s, glm::vec2 startPos, float length, glm::vec3 color);

#endif