/*
   /include/casyt/context.hpp

  Created at 2023-02-06 by @sauhd.
  Licensed under the MPL-3.0 license.
 */

#pragma once

#include <casyt/remote_package_info.hpp>
#include <casyt/target_info.hpp>

#include <string>
#include <vector>

namespace casyt {

    using std::vector;

    struct context {
        target_info current_target;
        vector<target_info> imported_targets;
        vector<remote_package_info> remote_packages;

        inline context(target_info const &current_target) : current_target(current_target) {}
    };
}
