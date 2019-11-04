
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

constexpr int kMaxPulse = 1000;

int main(int argc, char* argv[]) {
  hyped::utils::System::parseArgs(argc, argv);
  Logger log(true, 0);
  GpioCounter counter(log, 67);

  counter.start();

  while (counter.getStripeCounter().count.value < kMaxPulse) {
    // waiting to read kMaxPulse pulses
  }
  log.INFO("GPIOTEST", "Final pulse count %d", counter.getStripeCounter().count.value);
  
} // end of main
