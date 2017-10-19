#ifndef MESHSHADERS_H
#define MESHSHADERS_H

#include "../glad/glad.h"

class MeshShaders {
public:
    static GLuint staticMeshShaderProgram;
    static GLuint bonedMeshShaderProgram;
    static GLuint* currentProgram;
    static void init();
private:
    static void createStaticShader();
    static void createBonedShader();
};

#endif
