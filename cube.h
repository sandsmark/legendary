#ifndef __CUBE_H
#define __CUBE_H

#include "texture.h"
#include "rtt.h"
#include "vboobject.h"

class cube : public VboObject {
public:
    cube();
    ~cube();
    float* getVertices();
    int* getIndices();
    unsigned char* getColours();
    float* getCoords();
    void draw();

private:
    Texture *mat;
};

#endif
