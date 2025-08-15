# src/meson.build
libname = 'scad'
version = meson.project_version()

sources = [
  'scad.cpp',
  'obj2d.cpp',
  'obj3d.cpp',
]

headers = [
  'scad.h',
  'obj2d.h',
  'obj3d.h',
]

incdir = include_directories('../include')

conf_h = configuration_data()
conf_h.set('MYLIB_VERSION_MAJOR', version.split('.')[0])
conf_h.set('MYLIB_VERSION_MINOR', version.split('.')[1])
conf_h.set('MYLIB_VERSION_PATCH', version.split('.')[2])
conf_h.set('MYLIB_VERSION_STRING', version)

configure_file(
  output : 'scad_config.h',
  configuration : conf_h,
  install : true,
  install_dir : join_paths(get_option('includedir'), libname)
)

# build library(s)
lib_targets = []

if get_option('shared')
  shared_lib = shared_library(
    libname,
    sources,
    include_directories : incdir,
    version : version,
    soversion : version.split('.')[0],
    install : true,
  )
  lib_targets += shared_lib
  default_lib_target = shared_lib
endif

if get_option('static')
  static_lib = static_library(
    libname,
    sources,
    include_directories : incdir,
    install : true,
  )
  lib_targets += static_lib
  default_lib_target = static_lib
endif

pkgconfig = import('pkgconfig')
pkgconfig.generate(
  name : 'scad',
  description : 'Generator for OpenSCAD programs, and interface for generation.',
  version : version,
  libraries : lib_targets,
  subdirs : libname,
  install_dir : join_paths(get_option('libdir'), 'pkgconfig')
)

# export targets for subprojects
foreach t : lib_targets
  default_library = t
endforeach

# install headers (public)
install_headers(
  '../include/scad/obj2d.h',
  '../include/scad/obj3d.h',
  '../include/scad/scad.h',
)

scad_dep = declare_dependency(
  link_with : lib_targets, # probably not the best solution but it works
  include_directories : incdir
)
