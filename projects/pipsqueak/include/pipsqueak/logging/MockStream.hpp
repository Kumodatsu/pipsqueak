#pragma once

#include <ostream>
#include <streambuf>

namespace pipsqueak {

  class MockStream final : public std::ostream {
  public:
    MockStream() : std::ostream(&m_buffer) {}
  private:
    class VoidBuffer final : public std::streambuf {
    protected:
      inline int overflow(int _) override { return _; }
    };

    VoidBuffer m_buffer; 
  };

}
