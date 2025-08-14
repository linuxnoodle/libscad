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
  Circle2D(float radius): radius(radius) {}
  std::string generateCode();

  float radius;
};

class Square2D : public Object2D {
public:
  Square2D(
      float size,
      bool center
  ): width(size),
     height(size),
     center(center) {}
  Square2D(
      float width,
      float height,
      bool center
  ): width(width),
     height(height),
     center(center) {}
  std::string generateCode();

  float width;
  float height;
  bool center;
};

class Polygon2D : public Object2D {
public:
  Polygon2D(
      std::vector<Point2D> points,
      std::vector<Path2D> paths
  ): points(points),
     paths(paths) {}
  std::string generateCode();

  std::vector<Point2D> points;
  std::vector<Path2D> paths;
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
