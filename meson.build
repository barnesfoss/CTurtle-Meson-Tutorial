# This is a functional tutorial on how to build something using meson

# Every meson project starts with... a project call
# The Meson build language is based heavily off of Python so this should look familiar!
# A basic project setup requires two arguments
project(
  'MesonTurtle', # The name of your project
  'cpp' # What language it uses
)
# For more info check out https://mesonbuild.com/Reference-manual_functions.html#project


# Great, we now have a project setup!
# But now we need to actually compile main.cpp
# This is going to take more than two arguments because we are using C-Turtle
# Don't worry though, it's still not too difficult!
executable(
  'main', # The name of the executable that's output
          # if you are on a *nix system this will be verbatim, but if it's windows it will
          # be the name+.exe

  'main.cpp', # The file/files we are compiling together!
             # In this project we only have main.cpp, but if you want more you can use a list using brackets.

  dependencies: dependency('cturtle') # Finally we need to actually include C-Turtle
                                      # We do this by saying that main requires cturtle as a dependency
                                      # This can either be pulled from your system or from a .wrap file
)
# For more info see https://mesonbuild.com/Reference-manual_functions.html#executable
