#include <stdio.h>
#include "utils/io/gpio.hpp"
#include "utils/timer.hpp"
#include "sensors/gpio_counter.hpp"

namespace hyped {

using data::Data;
using data::StripeCounter;
using utils::io::GPIO;
using hyped::utils::Logger;

namespace sensors {

GpioCounter::GpioCounter(utils::Logger& log, int pin)
     : pin_(pin),
       sys_(utils::System::getSystem()),
       log_(log)
{
  // TODO(anyone): initialse pointer using `new` with the appropriate value of parameter `pin`
  keyence_ = new GPIO(pin, utils::io::gpio::kIn);
}

void GpioCounter::run()   // where does this function come from?
{
  uint8_t val = keyence_->wait();    // TODO(anyone): you will need to change this
  stripe_counter_.count.value = 0;    // TODO(anyone): look at data.hpp to see how this is handled
  stripe_counter_.count.timestamp =  utils::Timer::getTimeMicros();

  while (sys_.running_) {
    val = keyence_->wait();    // TODO(anyone): you will need to change this
    if (val == 1) {
      stripe_counter_.count.value = stripe_counter_.count.value+1;
      log_.DBG3("TEST-KEYENCE", "Stripe Count: %d", stripe_counter_.count.value);
      stripe_counter_.count.timestamp =  utils::Timer::getTimeMicros();
      stripe_counter_.operational = true;
    }
  }
}

StripeCounter GpioCounter::getStripeCounter()   // where does this function come from?
{
  return stripe_counter_;
}
}}  // namespace hyped::sensors
