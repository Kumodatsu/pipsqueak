#pragma once

#include <memory>
#include <string>

#include "pipsqueak/Common.hpp"

namespace pipsqueak {

  class Window {
  public:
    inline const std::string& title() const {
      return m_title;
    }

    inline U16 width() const {
      return m_width;
    }

    inline U16 height() const {
      return m_height;
    }

    virtual bool should_close() const = 0;
    virtual void update() = 0;
    virtual void swap_buffers() = 0;
    virtual void poll_events() = 0;
  protected:
    std::string m_title;
    U16         m_width;
    U16         m_height;

    Window(const std::string& title, U16 width, U16 height)
      : m_title(title)
      , m_width(width)
      , m_height(height)
    {}

    virtual ~Window() {}
    
    Window(Window&& other) = default;
    Window& operator = (Window&& other) = default;

    Window(const Window&)              = delete;
    Window& operator = (const Window&) = delete;
  };

}
