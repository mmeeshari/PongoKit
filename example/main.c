#include <pongo.h>

void m_preboot_hook()
{
    puts("Called pre-boot hook");
    return;
}

void hello() {
    puts("Hello world! And now continuing to XNU.");
    queue_rx_string("bootx\n"); // Adding boot XNU command to buffer
}

void module_entry() {
    preboot_hook = m_preboot_hook;
    command_register("hello", "Hello world!", hello);
}

char* module_name = "test_module";

struct llktrw_exports exported_symbols[] = {
    {.name = 0, .value = 0}
};
