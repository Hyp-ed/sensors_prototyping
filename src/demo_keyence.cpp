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
using hyped::sensors::GpioCounter;
using hyped::utils::Logger;
using namespace hyped::data;

// TODO(anyone): once done completing GpioCounter class, format this demo file to use that class thread
int main(int argc, char* argv[]) {
  hyped::utils::System::parseArgs(argc, argv);  // YOU NEED TO INITIALISE SYSTEM
  Logger log(true, 0);
  GpioCounter keyence(log, 66);
  keyence.start();
  StripeCounter counter = keyence.getStripeCounter();
  while (true) {
    StripeCounter new_count = keyence.getStripeCounter();
    if (new_count.count.value != counter.count.value){
      log.DBG3("Keyence", "Stripe Count: %d", new_count.count.value);
      counter = new_count;
    }


  }

  return 0;
  
} // end of main
