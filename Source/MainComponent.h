#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include "UI/HeaderBar.h"
#include "UI/SheetViewport.h"

/**
    Root component: the sticky header stacked above the scrolling canvas.

        <body>
            <header>…</header>
            <main id="canvas">…</main>
        </body>
*/
class MainComponent : public juce::Component
{
public:
    MainComponent();

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    HeaderBar     header;
    SheetViewport viewport;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};