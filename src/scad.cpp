#include "scad/scad.h"

std::string Scene::generateCode(){
  std::string buf;
  // fifo order
  for (unsigned int i = 0; i < objs.size(); ++i){
    buf += objs[i]->generateCode();
    if (i < objs.size() - 1)
      buf += "\n";
  }
  return buf;
}
