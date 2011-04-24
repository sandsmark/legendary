#ifndef C3DS_OBJECT_H
#define C3DS_OBJECT_H

#include "vboobject.h"

#include "c3dsparser.h"

#include <stdio.h>
#include <map>
#include <vector>

using std::string;

class c3ds_object : public VboObject
{
public:
    c3ds_object(string fileName);

    float* getVertices();
    int* getIndices();
    unsigned char* getColours();
    float* getCoords();

private:
    void parseFile(string fileName);

    float *m_vertices;
    int *m_indices;
    unsigned char *m_colours;
    float *m_coords;

};

#endif // C3DS_OBJECT_H
