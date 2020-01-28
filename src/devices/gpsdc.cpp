/**
 * \file gpsdc.cpp
 * \brief Provide implementation for gpsd client device class
 *
 * \author J.R. Versteegh <j.r.versteegh@orca-st.com>
 * \copyright
 * Copyright (C) 2020 Orca Software
 * \license
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "gpsdc.h"

// For context provider
#include "../loop.h"

using Gpsdc_client = gpsdc::Gpsd_client<Context_provider>;

using Gpsd_client_factory = Device_factory<Gpsd_client>;

static auto& gpsdc_devicefactory =
    add_device_factory("gpsdc", std::move(std::make_unique<Gpsd_client_factory>()));


// vim: autoindent syntax=cpp expandtab tabstop=2 softtabstop=2 shiftwidth=2
