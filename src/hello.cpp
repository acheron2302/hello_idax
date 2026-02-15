/// \file hello.cpp
/// \brief Minimal IDA Pro plugin template using idax
///
/// A simple "Hello, World!" plugin that demonstrates the basic structure
/// of an idax-based IDA Pro plugin. When activated, it prints a greeting
/// message to IDA's output window.
///
/// API surface exercised:
///   plugin (Plugin, Info, IDAX_PLUGIN macro),
///   ui (message)

#include <ida/idax.hpp>

#include <cstddef>

// ── Plugin class ────────────────────────────────────────────────────────

/// A minimal plugin that prints "Hello, World!" to the IDA output window.
///
/// This class inherits from ida::plugin::Plugin and implements the required
/// info() and run() methods. The IDAX_PLUGIN macro at file scope handles
/// the IDA plugin registration.
class HelloPlugin final : public ida::plugin::Plugin {
public:
    /// Return metadata about this plugin instance.
    /// This information is displayed in IDA's plugin menu and help system.
    ida::plugin::Info info() const override {
        return {
            .name    = "Hello",
            .hotkey  = "Ctrl-Alt-H",
            .comment = "Prints hello to output window",
            .help    = "Help text",
        };
    }

    /// Called when the user invokes the plugin.
    /// @param arg  user argument (typically 0)
    /// @return Status indicating success or failure
    ida::Status run(std::size_t) override {
        ida::ui::message("Hello, World!\n");
        return ida::ok();
    }
};

// ── Plugin registration ─────────────────────────────────────────────────

// Generate the IDA plugin export block for HelloPlugin.
// This macro must appear at file scope in exactly one .cpp file.
IDAX_PLUGIN(HelloPlugin);
