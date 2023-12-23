#include <pipsqueak/Window.hpp>

int main(int, char**) {
  auto window = pipsqueak::create_window("Pipsqueak", 640, 480);
  while (!window->should_close()) {
    window->update();
    window->swap_buffers();
    window->poll_events();
  }
  return 0;
}
