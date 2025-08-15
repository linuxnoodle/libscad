#include "scad/obj2d.h"

std::string Circle2D::generateCode() {
  return std::format("circle($fn = {}, $fa = {}, $fs = {}, r = {});", fn, fa, fs,
      radius);
}
std::string Square2D::generateCode() {
  return std::format("square($fn = {}, $fa = {}, $fs = {}, width = {}, height = {}, center = {});", fn, fa, fs,
      width, height, center);
}
std::string Polygon2D::generateCode() {
  std::string pointsFormat = "[";
  for (unsigned int i = 0; i < points.size(); ++i){
    pointsFormat += std::format("[{},{}]", points[i].x, points[i].y);
    if (i < points.size() - 1){
      pointsFormat += ",";
    }
  }
  pointsFormat += "]";

  std::string pathsFormat = "[";
  for (unsigned int i = 0; i < paths.size(); ++i){
    pathsFormat += "[";
    for (unsigned int j = 0; j < paths[i].size(); ++j){
      pathsFormat += std::format("[{},{}]", paths[i][j].x, paths[i][j].y);
      if (j < paths[i].size() - 1){
        pathsFormat += ",";
      }
    }
    pathsFormat += "]";
    if (i < paths.size() - 1){
      pathsFormat += ",";
    }
  }
  pathsFormat += "]";

  return std::format("polygon($fn = {}, $fa = {}, $fs = {}, points = {}, paths = {}, convexity = {});", fn, fa, fs,
      pointsFormat, pathsFormat, convexity);
}

std::string Text2D::generateCode() {
  return std::format("text($fn = {}, $fa = {}, $fs = {}, "
      "text = {}, font = {}, size = {}, "
      "halign = {}, valign = {}, "
      "spacing = {}, direction = {}, "
      "language = {}, script = {});",
      fn, fa, fs,
      text, font, size,
      halign, valign,
      spacing, direction,
      language, script);
}
