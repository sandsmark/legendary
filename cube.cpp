#include "cube.h"

#include "msg.h"
#include "rawtexture.h"

Cube::Cube() : VboObject() {
    if (reference_count == 1) {
        genBO();
        m_material = new RawTexture("legendary.raw");
        //mat = new CRenderToTextureMaterial;
        LOG("Cube VBO generated\n");
    }
}

Cube::~Cube() {
    delete m_material;
}

void Cube::draw() {
    m_material->Bind();
    VboObject::draw();
}

float* Cube::getVertices() {
    float vcube[] =
        {	-50.0, -50.0,  50.0, 	// 4 Front	0
          50.0,  50.0,  50.0,		// 1
          -50.0,  50.0,  50.0,	// 0		2
          50.0, -50.0,  50.0,		// 5

          50.0, -50.0,  50.0, 	// 5 Right	4
          50.0, -50.0, -50.0,		// 7
          50.0,  50.0, -50.0,		// 3		6
          50.0,  50.0,  50.0,		// 1

          -50.0, -50.0, -50.0, 	// 6 Bottom	8
          50.0, -50.0, -50.0,		// 7
          50.0, -50.0,  50.0,		// 5		10
          -50.0, -50.0,  50.0,	// 4

          -50.0, -50.0, -50.0, 	// 6 Left	12
          -50.0, -50.0,  50.0,	// 4
          -50.0,  50.0,  50.0,	// 0		14
          -50.0,  50.0, -50.0,	// 2

          50.0, -50.0, -50.0, 	// 7 Back	16
          -50.0, -50.0, -50.0,	// 6
          50.0,  50.0, -50.0,		// 3		18
          -50.0,  50.0, -50.0,	// 2

          -50.0,  50.0,  50.0, 	// 0 Top	20
          50.0,  50.0,  50.0,		// 1
          50.0,  50.0, -50.0,		// 3		22
          -50.0,  50.0, -50.0
        };	// 2
    VBO_size_vertices = sizeof(vcube);
    int vertices = sizeof(vcube)/sizeof(float);
    float *ret = new float[vertices];
    for ( int i=0; i < vertices; i++ ) {
        ret[i] = vcube[i];
    }
    return ret;
}

unsigned int* Cube::getIndices() {
    unsigned short int icube[] = {
        0, 1, 2,		1, 0, 3,
        4, 5, 6,		4, 6, 7,
        8, 9, 10,		8, 10, 11,
        12, 13, 14,		12, 14, 15,
        16, 17, 18,		18, 17, 23,
        20, 21, 22,		22, 23, 20
    };
    IBO_size_indices = sizeof(icube);
    indices = sizeof(icube)/sizeof(unsigned short int);
    unsigned short int *ret = new unsigned short int[indices];
    for ( int i=0; i < indices; i++ ) {
        ret[i] = icube[i];
    }
    return (unsigned int*)ret;
}

unsigned char* Cube::getColours() {
    unsigned char ccube[] = {
        000, 000, 000,  255, 255, 255,  255, 255, 255,  000, 000, 000, // Front
        000, 000, 000,  000, 000, 000,  000, 000, 000,  255, 255, 255, // Right
        000, 000, 000,  000, 000, 000,  000, 000, 000,  000, 000, 000, // Bottom
        000, 000, 000,  000, 000, 000,  255, 255, 255,  000, 000, 000, // Left
        000, 000, 000,  255, 255, 255,  255, 255, 255,  000, 000, 000, // Back
        255, 255, 255,  255, 255, 255,  000, 000, 000,  000, 000, 000
    };// Top
    VBO_size_colours = sizeof(ccube);
    int colours = sizeof(ccube)/sizeof(unsigned char);
    unsigned char *ret = new unsigned char[colours];
    for ( int i=0; i < colours; i++ ) {
        ret[i] = ccube[i];
    }
    return ret;
}

float* Cube::getCoords() {
    float tcube[] =
        {	0.0, 1.0,  1.0, 0.0,  0.0, 0.0,  1.0, 1.0,
          0.0, 1.0,  1.0, 1.0,  1.0, 0.0,  0.0, 0.0,
          0.0, 1.0,  1.0, 1.0,  1.0, 0.0,  0.0, 0.0,
          0.0, 1.0,  1.0, 1.0,  1.0, 0.0,  0.0, 0.0,
          0.0, 1.0,  1.0, 1.0,  0.0, 0.0,  1.0, 0.0,
          0.0, 1.0,  1.0, 1.0,  1.0, 0.0,  0.0, 0.0
        };
    VBO_size_coords = sizeof(tcube);
    int coords = sizeof(tcube)/sizeof(float);
    float *ret = new float[coords];
    for ( int i=0; i < coords; i++ ) {
        ret[i] = tcube[i];
    }
    return ret;
}


float* Cube::getNormals() {
    return NULL;
}
