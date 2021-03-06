/*
 *  Copyright © 2017-2020 Wellington Wallace
 *
 *  This file is part of PulseEffects.
 *
 *  PulseEffects is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PulseEffects is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with PulseEffects.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef BASS_ENHANCER_HPP
#define BASS_ENHANCER_HPP

#include "plugin_base.hpp"

class BassEnhancer : public PluginBase {
 public:
  BassEnhancer(const std::string& tag, const std::string& schema, const std::string& schema_path);
  BassEnhancer(const BassEnhancer&) = delete;
  auto operator=(const BassEnhancer&) -> BassEnhancer& = delete;
  BassEnhancer(const BassEnhancer&&) = delete;
  auto operator=(const BassEnhancer &&) -> BassEnhancer& = delete;
  ~BassEnhancer() override;

  GstElement* bass_enhancer = nullptr;

  sigc::connection harmonics_connection;

  sigc::signal<void, double> harmonics;

 private:
  void bind_to_gsettings();
};

#endif
