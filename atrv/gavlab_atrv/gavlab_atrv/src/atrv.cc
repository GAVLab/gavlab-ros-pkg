#include "atrv/atrv.h"

/***** Inline Functions *****/

inline void defaultInfoCallback(const std::string &msg) {
  std::cout << "ATRV Info: " << msg << std::endl;
}

inline void defaultExceptionCallback(const std::exception &error) {
  std::cerr << "ATRV Unhandled Exception: " << error.what();
  std::cerr << std::endl;
  throw(error);
}

using namespace atrv;
using namespace mdc2250;

/***** MDC2250 Class Functions *****/

ATRV::ATRV() {
  // Set default callbacks
  this->handle_exc = defaultExceptionCallback;
}

ATRV::~ATRV() {
  
}

void ATRV::connect(std::string port1, std::string port2) {
  
}

void MDC2250::disconnect() {
  
}

