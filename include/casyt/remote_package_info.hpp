/*
   /include/casyt/remote_package_info.hpp

  Created at 2023-02-08 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#pragma once

#include <optional>
#include <sstream>
#include <string>
#include <string_view>

namespace casyt {

    using std::optional;
    using std::string;
    using std::string_view;
    using std::stringstream;

    struct remote_package_info {
        inline remote_package_info(string_view owner_name, string_view package_name, string_view version)
            : _owner_name(owner_name), _package_name(package_name), _version(version) {}

        inline remote_package_info(string_view owner_name, string_view package_name) : _owner_name(owner_name), _package_name(package_name) {}

        inline string owner_name() const { return _owner_name; }
        inline string package_name() const { return _package_name; }
        inline string version() const { return _version.value_or("?"); }

        inline string to_string() const {
            stringstream ss;

            ss << _owner_name << "/" << _package_name;

            if (_version.has_value()) {
                ss << "@" << _version.value();
            }

            return ss.str();
        }

      protected:
        string _owner_name;
        string _package_name;
        optional<string> _version;
    };
}
