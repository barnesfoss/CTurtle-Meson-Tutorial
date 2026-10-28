#include "CTurtle.hpp"

using namespace cturtle;

int main() {
  TurtleScreen scr;
  Turtle t(scr);
  t.write("Hello World!");
  scr.exitonclick();
  return 0;
}
