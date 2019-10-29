// Demo file to implememt a keyence sensor 
// Initialise a gpio object 
// Start and inifinte loop 
// call wait on the pin 
// have a condiition to check the value read from that pin 
// and log the amount of stripes the sensor has read

#include "utils/concurrent/thread.hpp"
#include "utils/io/gpio.hpp"
#include "sensors/gpio_counter.hpp"
#include "utils/logger.hpp"
#include "utils/system.hpp"

using hyped::utils::io::GPIO;
using hyped::utils::Logger;

constexpr uint32_t kStripeNum = 9999999;

// TODO(anyone): once done completing GpioCounter class, format this demo file to use that class thread
int main(int argc, char* argv[]) {
  hyped::utils::System::parseArgs(argc, argv);  // YOU NEED TO INITIALISE SYSTEM
  Logger log(true, 0);
  GPIO pin(66, hyped::utils::io::gpio::kIn);
  uint32_t stripe_count = 0; 
  
  while (stripe_count < kStripeNum) {
    int val = pin.wait();
    if (val == 1) {
      stripe_count++; 
      log.DBG("TEST-GpioCounter", "Stripe Count: %d", stripe_count);
    }
  }
  
} // end of main
