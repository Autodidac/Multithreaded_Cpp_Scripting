
#include "aeditor.hpp"
#include "aui.hpp"
#include "afilewatch.hpp"

namespace almond {

void editor_run() {
    aui::begin_window("epoch editor", {20, 20}, {400, 300});

    static auto files = get_file_states("epoch_gui_editor/src/scripts");
    scan_and_mark_changes(files);

    for (auto& f : files) {
        aui::label(f.path);
    }

    aui::end_window();
}

}
