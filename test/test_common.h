#include <stdio.h>
#include <string.h>
#include <string>

#include <boost/test/unit_test.hpp>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>

namespace tt = boost::test_tools;
namespace ut = boost::unit_test;
namespace asio = boost::asio;

std::string usb_device;

tt::assertion_result usb_available(ut::test_unit_id test_id) {
  const char* device_str = getenv("USB");
  if (device_str != nullptr) {
    usb_device = device_str;
  }
  else {
    usb_device = "";
  }
  if (usb_device == "") {
    usb_device = "2639:0017";
  }

  FILE *lsusb = popen("/usr/bin/lsusb", "r");
  if (lsusb == nullptr) {
    std::cout << "Failed to popen lsusb" << std::endl;
    return false;
  }
  char buffer[1024];
  char* line = fgets(buffer, sizeof(buffer), lsusb);
  bool usb_present = false;
  while (line != nullptr) {
    usb_present = strstr(line, usb_device.c_str()) != nullptr;
    if (usb_present)
      break;
    line = fgets(buffer, sizeof(buffer), lsusb);
  }
  pclose(lsusb);

  return usb_present;
}

struct Ctx {
  static asio::io_context& get_context() {
    static asio::io_context instance;
    return instance;
  }
};