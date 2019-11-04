#ifndef SENSORS_GPIO_COUNTER_HPP_
#define SENSORS_GPIO_COUNTER_HPP_

#include <cstdint>

#include "sensors/interface.hpp"
#include "utils/concurrent/thread.hpp"
#include "utils/system.hpp"
#include "utils/logger.hpp"

namespace hyped {

using utils::Logger;
using utils::concurrent::Thread;
using utils::System;
using utils::io::GPIO;
using data::StripeCounter;
using sensors::GpioInterface;

namespace sensors {

class GpioCounter: public GpioInterface, public Thread {  // TODO(anyone): inherit GpioInterface class from interface.hpp and Thread from thread.hpp
 public:
  GpioCounter(utils::Logger& log, int pin);
  ~GpioCounter() {}
  // TODO(anyone): override two functions here from GpioInterface and Thread
  void run() override; 
  StripeCounter getStripeCounter() override;
  


 private:
  int pin_;
  // TODO(anyone): add GPIO pointer as class variable (name it keyence_)
  GPIO* keyence_;
  System&  sys_;
  utils::Logger& log_;
  data::StripeCounter stripe_counter_;
};
}}  // namespace hyped::sensors

#endif  // SENSORS_GPIO_COUNTER_HPP_
