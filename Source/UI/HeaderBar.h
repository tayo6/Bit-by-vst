#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include "BlueprintButton.h"
#include "TextLabel.h"
#include "Theme.h"

/**
        <header>
            <h1>HUH · BLUEPRINT PREVIEW</h1>
            <button>−</button>
            <span id="zl">100%</span>
            <button>+</button>
            <button>FIT</button>
            <button>DOWNLOAD SVG</button>
        </header>

    Purely presentational: it reports clicks through std::function callbacks and
    never touches the sheet itself.
*/
class HeaderBar : public juce::Component
{
public:
    HeaderBar();

    void paint (juce::Graphics&) override;
    void resized() override;

    /** label.textContent = Math.round(zoom * 100) + '%' */
    void setZoomLevel (float zoom);

    std::function<void()> onZoomOut;
    std::function<void()> onZoomIn;
    std::function<void()> onFitWidth;
    std::function<void()> onDownloadSvg;

private:
    TextLabel title;
    TextLabel zoomReadout;

    BlueprintButton zoomOutButton;
    BlueprintButton zoomInButton;
    BlueprintButton fitButton;
    BlueprintButton downloadButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderBar)
};