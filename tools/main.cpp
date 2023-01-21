/*
   main.cpp - //tools/-casyt

  Created at 2023-01-21 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#include <casyt/driver.hpp>

#include <future>

int main(int argc, char const **argv) {
    std::future<int> f = std::async(std::launch::async, casyt::entry_point, argc, argv);

    f.wait();

    return f.get();
}
