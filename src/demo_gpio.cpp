
#include "utils/concurrent/thread.hpp"
#include "utils/io/gpio.hpp"
#include "sensors/gpio_counter.hpp"
#include "utils/logger.hpp"
#include "utils/system.hpp"
#include "utils/timer.hpp"

using hyped::utils::io::GPIO;
using hyped::utils::Logger;
using hyped::utils::Timer;

int main(int argc, char* argv[]) {
  hyped::utils::System::parseArgs(argc, argv);
  Logger log(true, 0);
  GPIO pin(66, hyped::utils::io::gpio::kOut);

  double rps = 50;

  uint64_t start_time = Timer::getTimeMicros();
  uint64_t current_time = start_time;
  while (1) {
    current_time = Timer::getTimeMicros();
    if (current_time - start_time > (1/rps)) {
      pin.set();
      pin.clear();
    }
  }
  
} // end of main
