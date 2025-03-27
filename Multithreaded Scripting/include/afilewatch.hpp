
#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace almond {
struct file_state {
    std::string path;
    std::uint64_t last_write_time;
    std::uint64_t hash;
    bool dirty;
};

std::vector<file_state> get_file_states(const std::string& folder);
void scan_and_mark_changes(std::vector<file_state>& files);
}
