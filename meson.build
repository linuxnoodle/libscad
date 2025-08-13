project('scad', 'cpp',
  version : '1.0.0',
  default_options : [
    'cpp_std=c++20',
    'warning_level=2',
    'buildtype=release'
  ]
)

subdir('src')

if get_option('debug')
  add_project_arguments('-Wall', '-Wextra', language : 'cpp')
endif

if get_option('enable_tests')
  subdir('tests')
endif

