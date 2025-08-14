#include "scad/obj3d.h"

std::string Sphere3D::generateCode(){
  return std::format("sphere($fn = {}, $fa = {}, $fs = {}, {});", fn, fa, fs,
      radius);
}

std::string Cube3D::generateCode(){
  return std::format("cube($fn = {}, $fa = {}, $fs = {}, size = [{},{},{}], center = {});", fn, fa, fs,
      width, depth, height, center);
}

std::string Cylinder3D::generateCode(){
  return std::format("cylinder($fn = {}, $fa = {}, $fs = {}, h = {}, r1 = {}, r2 = {}, center = {});", fn, fa, fs,
      height, radius1, radius2, center);
}

std::string Polyhedron3D::generateCode(){
  std::string pointsFormat = "[";
  for (unsigned int i = 0; i < points.size(); ++i){
    pointsFormat += std::format("[{},{},{}]", points[i].x, points[i].y, points[i].z);
    if (i < points.size() - 1){
      pointsFormat += ",";
    }
  }
  pointsFormat += "]";

  std::string facesFormat = "[";
  for (unsigned int i = 0; i < faces.size(); ++i){
    facesFormat += "[";
    for (unsigned int j = 0; j < faces[i].size(); ++j){
      facesFormat += std::format("[{},{},{}]", faces[i][j].x, faces[i][j].y, faces[i][j].z);
      if (j < faces[i].size() - 1){
        facesFormat += ",";
      }
    }
    facesFormat += "]";
    if (i < faces.size() - 1){
      facesFormat += ",";
    }
  }
  facesFormat += "]";

  return std::format("polyhedron($fn = {}, $fa = {}, $fs = {}, points = {}, faces = {}, convexity = {});", fn, fa, fs,
      pointsFormat, facesFormat, convexity);
}
