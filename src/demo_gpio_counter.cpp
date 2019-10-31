
#include "utils/concurrent/thread.hpp"
#include "utils/io/gpio.hpp"
#include "sensors/gpio_counter.hpp"
#include "utils/logger.hpp"
#include "utils/system.hpp"
#include "data/data.hpp"

using hyped::utils::io::GPIO;
using hyped::utils::Logger;
using hyped::sensors::GpioCounter;
using hyped::data::StripeCounter;

constexpr uint32_t kStripeNum = 9999999;

int main(int argc, char* argv[]) {
  hyped::utils::System::parseArgs(argc, argv);
  Logger log(true, 0);
  GpioCounter counter(log, 67);

  counter.start();

  while (1) {
    log.INFO("GPIOTEST", "Pulse count %d", counter.getStripeCounter().count.value);
  }
  
} // end of main
