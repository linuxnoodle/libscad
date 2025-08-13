#ifndef OBJ2D_H
#define OBJ2D_H

#include <string>
#include <format>
#include <vector>

struct Point2D {    
    float x, y;
};    
      
typedef std::vector<Point2D> Path2D;

class Object2D {
public:
  virtual std::string generateCode() = 0; // -> openscad function call
  virtual ~Object2D();
  
  // TODO: add ways to modify these parameters
  float fn = 0;  // fixed number of fragments in 360 degrees. Values of 3 or more override fa and fs 
  float fa = 12; // minimum angle (in degrees) of each fragment
  float fs = 2;  // minimum circumferential length of each fragment
};

#endif
