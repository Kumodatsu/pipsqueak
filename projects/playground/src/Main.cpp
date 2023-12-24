#include <iostream>
#include <memory>
#include <pipsqueak/App.hpp>

using namespace pipsqueak;

class Playground : public App {
public:
protected:
  void on_update(std::chrono::duration<F32> delta) override {
    ++m_update_count;
    m_elapsed += delta;
    static constexpr auto one_second = decltype(m_elapsed)(1.0f);
    if (m_elapsed >= one_second) {
      m_elapsed -= one_second;
      std::cout << "FPS: " << m_update_count << std::endl;
      m_update_count = 0;
    }
  }
private:
  I32 m_update_count = 0;
  std::chrono::duration<F32> m_elapsed {0};
};

int main(int, char**) {
  std::unique_ptr<App> app = std::make_unique<Playground>();
  app->run();
  return 0;
}
