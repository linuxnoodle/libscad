# libscad

**libscad** is a modern C++20 library designed to be an intermediary for OpenSCAD.

---

## Features
- [X] 3D Object scripting
- [ ] 2D Object scripting
- [ ] Transforms, extrusions
- [ ] Direct binary stl generation
- [ ] 

---

## Project Structure
├── builddir/
├── include/
│ └── scad/
│   ├── obj2d.h
│   ├── obj3d.h
│   └── scad.h
├── src/
│ ├── meson.build
│ ├── obj2d.cpp
│ ├── obj3d.cpp
│ └── scad.cpp
├── tests/
│ ├── meson.build
│ └── test_libscad.cpp
├── meson.build
├── meson_options.txt
└── README.md

- `include/scad/` — Public headers
- `src/` — Library source and build rules
- `tests/` — Unit tests for the library
- `meson.build` files — Meson build definitions
- `meson_options.txt` — Build options configuration

---

## Compilation Prerequisites

- Meson build system (≥ 1.8.3 recommended)
- C++20 compiler
- Ninja

---

## Building


```bash
git clone https://github.com/linuxnoodle/libscad
meson setup builddir
meson compile -C builddir
```

The resulting file should be `builddir/src/libscad.so.0.0.0`.

---

## Installing

```bash
meson install -C builddir
```

This should install the .so file to `/usr/lib` and the headers to `/usr/include`.

---

## Example Code

```cpp

```
