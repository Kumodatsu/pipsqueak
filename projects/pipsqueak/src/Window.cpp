#include "pipsqueak/Window.hpp"
#include "pipsqueak/renderer/opengl/Window.hpp"

namespace pipsqueak {

  std::unique_ptr<Window> create_window(
    const std::string& title, U16 width, U16 height
  ) {
    return std::make_unique<opengl::Window>(title, width, height);
  }

}
