#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

/**
    The flat CSS button:

        button {
            background:#eaf2fa; border:1px solid #7fb2d9; color:#4a7ba6;
            padding:6px 12px; border-radius:6px;
            cursor:pointer; font-family:inherit;
        }
        button:hover { background:#dcebf7; }

    Auto-sized: width = text + 2×12 padding + 2×1 border,
                 height = line height + 2×6 padding + 2×1 border.
*/
class BlueprintButton : public juce::Button
{
public:
    explicit BlueprintButton (const juce::String& buttonText);

    void paintButton (juce::Graphics& g,
                      bool shouldDrawButtonAsHighlighted,
                      bool shouldDrawButtonAsDown) override;

    int getPreferredWidth() const;
    static int getPreferredHeight();
};