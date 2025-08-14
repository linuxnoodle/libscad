#ifndef SCAD_H
#define SCAD_H

#include <string>
#include <format>
#include <vector>

class Object {
public:
  virtual std::string generateCode() = 0; // -> openscad function call
  virtual ~Object() {}
  
  // TODO: add ways to modify these parameters other than direct manipulation
  float fn = 0;  // fixed number of fragments in 360 degrees. Values of 3 or more override fa and fs 
  float fa = 12; // minimum angle (in degrees) of each fragment
  float fs = 2;  // minimum circumferential length of each fragment
};


#endif
