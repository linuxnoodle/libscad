#ifndef OBJ3D_H
#define OBJ3D_H

#include <string>
#include <format>
#include <vector>

struct Point3D {    
    float x, y, z;        
};    
      
typedef std::vector<Point3D> Face3D;

class Object3D {
public:
  virtual std::string generateCode() = 0; // -> openscad function call
  virtual ~Object3D();
  
  // TODO: add ways to modify these parameters
  float fn = 0;  // fixed number of fragments in 360 degrees. Values of 3 or more override fa and fs 
  float fa = 12; // minimum angle (in degrees) of each fragment
  float fs = 2;  // minimum circumferential length of each fragment
};

class Sphere3D : public Object3D {
public:
  Sphere3D(float radius): radius(radius) {}
  std::string generateCode();
private:
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
private:
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
private:
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
private:
  std::vector<Point3D> points;
  std::vector<Face3D> faces;
  int convexity;
};

#endif
