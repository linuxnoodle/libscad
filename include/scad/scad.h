#ifndef SCAD_H
#define SCAD_H

#include <memory>
#include <string>
#include <format>
#include <vector>

class Object {
public:
  virtual std::string generateCode() = 0; // -> openscad function call, overridden by derivative classes
  virtual std::shared_ptr<Object> clone() const = 0;
  virtual ~Object() {}
  
  float fn = 0;  // fixed number of fragments in 360 degrees. Values of 3 or more override fa and fs 
  float fa = 12; // minimum angle (in degrees) of each fragment
  float fs = 2;  // minimum circumferential length of each fragment
};

class Scene {
private:
  std::vector<std::shared_ptr<Object>> objs; // polymorphism requires pointers to avoid slicing
public:
  std::string generateCode();
  std::shared_ptr<Object> at(unsigned int idx) { return objs[idx]; }
  // Hiding the shared_ptr nature from user
  // It's a bit wasteful to clone the object instead of just reusing it
  // TODO: Look into ways to refactor this
  void append(const Object &obj) { objs.push_back(obj.clone()); }
  void remove(unsigned int idx) { objs.erase(objs.begin() + idx); }
  unsigned int size() { return objs.size(); }
};

#endif
