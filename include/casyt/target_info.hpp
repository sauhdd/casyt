/*
   /include/casyt/target_info.hpp

  Created at 2023-02-06 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#pragma once

#include <initializer_list>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace casyt {

    using std::initializer_list;
    using std::optional;
    using std::string;
    using std::string_view;
    using std::vector;

    struct target_info {
        inline target_info(string_view name) : _name(name) {}
        inline target_info(string_view name, initializer_list<string_view> path) : _name(name), _path(path.begin(), path.end()) {}
        inline target_info(string_view name, string_view anchor, initializer_list<string_view> path)
            : _name(name), _anchor(anchor), _path(path.begin(), path.end()) {}

        inline ~target_info() = default;

        inline string name() const { return _name; }
        inline string anchor() const { return _anchor.value_or("-unknown"); }
        inline vector<string> path() const { return _path; }

        inline string to_string() const {
            std::stringstream ss;

            if (_anchor.has_value()) {
                ss << "@" << _anchor.value();
            }

            ss << "//";

            for (auto const &e : _path) {
                ss << e << "/";
            }

            ss << ":" << _name;

            return ss.str();
        }

      protected:
        string _name;
        optional<string> _anchor;
        vector<string> _path;
    };
}
