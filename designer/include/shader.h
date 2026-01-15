
#ifndef _SHADER_H_
#define _SHADER_H_

#include <GL/glew.h>
#include <string>

class Shader {
    public:
    unsigned int ID; // shader program id
    Shader(const char* vertexPath, const char* fragmentPath);
    void use(); // active shader
};

#endif