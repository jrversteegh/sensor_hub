#define BOOST_TEST_MODULE ublox_test
#include <boost/test/unit_test.hpp>

#include "../src/devices/ublox_impl.h"
#include "../src/types.h"

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdint>
#include <algorithm>


using namespace ubx;


BOOST_AUTO_TEST_CASE(ublox_parse_acceleration_test) {
  std::string data = "\x40\x20\x0c\xbd\x77\x48\x07\xbc\x0e\xdc\x7b\x41\x1c\xd1\x56";
  /*
  auto cur = data.begin();
  ubx_parser::Acceleration acceleration;
  BOOST_TEST(std::is_floating_point<parser::Acceleration::bytes_type>::value);
  auto result = x3::parse(cur, data.end(), ubx_parser::acceleration, acceleration);
  BOOST_TEST(result);
  BOOST_TEST(acceleration.data.size() == 3);
  BOOST_TEST(acceleration.data[0] == to_float(data.data() + 3));
  BOOST_TEST(acceleration.data[1] == to_float(data.data() + 7));
  BOOST_TEST(acceleration.data[2] == to_float(data.data() + 11));
  */
}

cbytes_t empty_packet = { 0xB5, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
cbytes_t cfg_gnss_dummy = { 0xB5, 0x62, 0x06, 0x3E, 0x01, 0x00, 0x88, 0xCD, 0xA1 };

BOOST_AUTO_TEST_CASE(ublox_data_packet_test) {
  auto packet = parser::Data_packet();
  BOOST_TEST(packet.get_packet() == empty_packet);
  packet = parser::Data_packet(command::cls_cfg, command::cfg::gnss, { 0x88 });
  BOOST_TEST(packet.get_packet() == cfg_gnss_dummy);
}

// Test packet received from actual ublox device in reponse to CFG::PRT command
cbytes_t ack_nak = { 0xb5, 0x62, 0x05, 0x00, 0x02, 0x00, 0x06, 0x00, 0x0d, 0x32 };
BOOST_AUTO_TEST_CASE(ublox_checksum_test) {
  auto packet = parser::Data_packet(command::cls_ack, command::ack::nak, {command::cls_cfg, command::cfg::prt});
  BOOST_TEST(packet.get_packet() == ack_nak);
}

BOOST_AUTO_TEST_CASE(sensor_data_test) {
  ubx::parser::Sensor_data sd;
  sd.data = 0x5FFFFFF;
  sd.stag = 0;
  BOOST_TEST(sd.get_value(25600) == Quantity::ryr);
  BOOST_TEST(sd.get_value(25600) == (M_PI * -1.0 / (4096.0 * 180.0)));
  BOOST_TEST(sd.get_value(25600) == Data_stamp{-1.0});
}
