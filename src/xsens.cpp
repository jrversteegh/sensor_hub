/**
 * \file xsens.cpp
 * \brief Provide implementation for Xsens device base class
 *
 * \author J.R. Versteegh <j.r.versteegh@orca-st.com>
 * \copyright
 * (C) 2018 Damen Shipyards. All rights reserved.
 * \license
 * This software is proprietary. Any use without written
 * permission from the copyright holder is strictly 
 * forbidden.
 */

#include "xsens.h"  

#include <memory>

using Xsens_MTi_G_710_usb = Xsens_MTi_G_710<Usb>;
using Xsens_MTi_G_710_serial = Xsens_MTi_G_710<asio::serial_port>;
using Xsens_MTi_G_710_usb_factory = Device_factory<Xsens_MTi_G_710_usb>;
using Xsens_MTi_G_710_serial_factory = Device_factory<Xsens_MTi_G_710_serial>;

static auto& mti_g_710_usb_factory = 
    add_device_factory("xsens_mti_g_710_usb", std::move(std::make_unique<Xsens_MTi_G_710_usb_factory>()));
static auto& mti_g_710_serial_factory = 
    add_device_factory("xsens_mti_g_710_serial", std::move(std::make_unique<Xsens_MTi_G_710_serial_factory>()));


cdata_t goto_config_command = {packet_start, sys_command, 0x30, 0x00, 0xD1};
cdata_t goto_measurement_command = {packet_start, sys_command, 0x10, 0x00, 0xF1};
cdata_t config_ok = { packet_start, sys_command, 0x31, 0x00, 0xD0};
cdata_t measurement_ok = { packet_start, sys_command, 0x11, 0x00, 0xF0};

// vim: autoindent syntax=cpp expandtab tabstop=2 softtabstop=2 shiftwidth=2
