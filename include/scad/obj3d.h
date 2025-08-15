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
  Sphere3D(float radius = 1): radius(radius) {}
  std::string generateCode();
  std::shared_ptr<Object> clone() const override {
      return std::make_shared<Sphere3D>(*this);
  }

  float radius;
};

class Cube3D: public Object3D {
public:
  Cube3D(
      float size,
      bool center = false
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
  std::shared_ptr<Object> clone() const override {
      return std::make_shared<Cube3D>(*this);
  }

  float width, depth, height;
  bool center;
};

class Cylinder3D : public Object3D {
public:
  Cylinder3D(
      float height = 1,
      float radius = 1,
      bool center = false
  ): height(height),
     radius1(radius),
     radius2(radius),
     center(center) {}
  Cylinder3D(
      float height = 1,
      float radius1 = 1,
      float radius2 = 1,
      bool center = false
  ): height(height),
     radius1(radius1),
     radius2(radius2),
     center(center) {}
  std::string generateCode();
  std::shared_ptr<Object> clone() const override {
      return std::make_shared<Cylinder3D>(*this);
  }

  float height;
  float radius1, radius2;
  bool center;
};

class Polyhedron3D : public Object3D {
public:
  Polyhedron3D(
      std::vector<Point3D> points,
      std::vector<Face3D> faces,
      int convexity = 1
  ): points(points),
     faces(faces),
     convexity(convexity) {}
  std::string generateCode();
  std::shared_ptr<Object> clone() const override {
      return std::make_shared<Polyhedron3D>(*this);
  }
  std::vector<Point3D> points;
  std::vector<Face3D> faces;
  int convexity;
};

#endif
