#ifndef OBJ2D_H
#define OBJ2D_H

#include "scad/scad.h"

struct Point2D {    
    float x, y;
};    
      
typedef std::vector<Point2D> Path2D;

class Object2D : public Object {};

class Circle2D : public Object2D {
public:
  Circle2D(float radius = 1): radius(radius) {}
  std::string generateCode();
  std::shared_ptr<Object> clone() const override {
    return std::make_shared<Circle2D>(*this);
  }

  float radius;
};

class Square2D : public Object2D {
public:
  Square2D(
      float size = 1,
      bool center = false
  ): width(size),
     height(size),
     center(center) {}
  // I HATE AMBIGUOUS OVERLOADING
  // HOLY HELL C++ JUST ADD NAMED PARAMETERS!!
  Square2D(
      float width,
      float height,
      bool center = false
  ): width(width),
     height(height),
     center(center) {}
  std::string generateCode();
  std::shared_ptr<Object> clone() const override {
    return std::make_shared<Square2D>(*this);
  }

  float width;
  float height;
  bool center;
};

class Polygon2D : public Object2D {
public:
  Polygon2D(
      std::vector<Point2D> points,
      std::vector<Path2D> paths = {},
      int convexity = 1
  ): points(points),
     paths(paths),
     convexity(convexity) {}
  std::string generateCode();
  std::shared_ptr<Object> clone() const override {
        return std::make_shared<Polygon2D>(*this);
    }

  std::vector<Point2D> points;
  std::vector<Path2D> paths;
  int convexity;
};

class Text2D : public Object2D {
public:
  Text2D(
      std::string text,
      std::string font = "Liberation Sans:style=Regular",
      float size = 10,
      std::string halign = "left",
      std::string valign = "baseline",
      float spacing = 1,
      std::string direction = "ltr",
      std::string language = "en",
      std::string script = "latin"
  ): text(text),
     font(font),
     size(size),
     halign(halign),
     valign(valign),
     spacing(spacing),
     direction(direction),
     language(language),
     script(script) {}
  std::string generateCode();
  std::shared_ptr<Object> clone() const override {
      return std::make_shared<Text2D>(*this);
  }

  std::string text;
  std::string font;
  float size;
  std::string halign;
  std::string valign;
  float spacing;
  std::string direction;
  std::string language;
  std::string script;
};
#endif
