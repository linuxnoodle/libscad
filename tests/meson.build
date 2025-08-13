# tests/meson.build
gtest_proj = subproject('gtest')

gtest_dep = gtest_proj.get_variable('gtest_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

tests_src = [
  'test_libscad.cpp',
  'gtest-all.cpp'
]

e = executable('g',
  'test_libscad.cpp',
  include_directories : include_directories('../include'),
  dependencies : [gtest_dep, gmock_dep, scad_dep],
)

test('gtest_scad', e)
