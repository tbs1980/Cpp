#include "boost/date_time/posix_time/posix_time.hpp"
#include <iostream>

int
main()
{
  using namespace boost::posix_time;
  using namespace boost::gregorian;

  //get the current time from the clock -- one second resolution
  ptime now = second_clock::local_time();
  //Get the date part out of the time
  date today = now.date();
  date tomorrow = today + days(1);
  ptime tomorrow_start(tomorrow); //midnight

  //iterator adds by one hour
  time_iterator titr(now,hours(1));
  for (; titr < tomorrow_start; ++titr) {
    std::cout << to_simple_string(*titr) << std::endl;
  }

  time_duration remaining = tomorrow_start - now;
  std::cout << "Time left till midnight: "
            << to_simple_string(remaining) << std::endl;
  return 0;
}
