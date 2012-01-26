#include "atrv/atrv.h"

using namespace atrv;

int run() {
  try {
    ATRV my_atrv;
    my_atrv.connect("/dev/tty.USA49Wfd124P2.2",
                    "/dev/tty.USA49Wfd124P1.1", 3000, true);

    std::cout << "Moving..." << std::endl;
    my_atrv.move(1.0, 0.0);
    boost::this_thread::sleep(boost::posix_time::milliseconds(2000));
  } catch (const std::exception &e) {
    std::cerr << "Unhandled exception: " << e.what() << std::endl;
    throw(e);
  }

  return 0;
}

int main(void) {
  return run();
}
