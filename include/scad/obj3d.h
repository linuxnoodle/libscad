#ifndef OBJ3D_H
#define OBJ3D_H

#include "scad/scad.h"

struct Point3D {    
    float x, y, z;        
};    
      
typedef std::vector<Point3D> Face3D;

// Semantic difference, different transformations possible
class Object3D : public Object {};

class Sphere3D : public Object3D {
public:
  Sphere3D(float radius): radius(radius) {}
  std::string generateCode();

  float radius;
};

class Cube3D: public Object3D {
public:
  Cube3D(
      float size,
      bool center
  ): width(size),
     depth(size),
     height(size),
     center(center) {}
  Cube3D(
      float width,
      float depth,
      float height,
      bool center
  ): width(width),
     depth(depth),
     height(height),
     center(center) {}
  std::string generateCode();

  float width, depth, height;
  bool center;
};

class Cylinder3D : public Object3D {
public:
  Cylinder3D(
      float height,
      float radius,
      bool center
  ): height(height),
     radius1(radius),
     radius2(radius),
     center(center) {}
  Cylinder3D(
      float height,
      float radius1,
      float radius2,
      bool center
  ): height(height),
     radius1(radius1),
     radius2(radius2),
     center(center) {}
  std::string generateCode();

  float height;
  float radius1, radius2;
  bool center;
};

class Polyhedron3D : public Object3D {
public:
  Polyhedron3D(
      std::vector<Point3D> points,
      std::vector<Face3D> faces,
      int convexity
  ): points(points),
     faces(faces),
     convexity(convexity) {}
  std::string generateCode();

  std::vector<Point3D> points;
  std::vector<Face3D> faces;
  int convexity;
};

#endif
