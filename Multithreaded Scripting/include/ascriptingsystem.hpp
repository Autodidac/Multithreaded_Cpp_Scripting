
#pragma once
#include <string>
struct TaskScheduler;

namespace almond {
bool load_or_reload_script(const std::string& name, TaskScheduler& scheduler);
}
