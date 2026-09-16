#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include "BlueprintSheet.h"

/**
    Mirrors  main { overflow:auto; padding:24px }  plus the zoom/fit logic from
    the HTML <script> block. Owns the zoom level; the header merely reads it.

    The sheet is a fixed 1200 × 800 component; zoom is applied with
    Component::setTransform, which scales about the sheet's own top-left, so the
    24px padding stays exactly 24px at every zoom level — same as the browser.
*/
class SheetViewport : public juce::Component
{
public:
    SheetViewport();

    void paint (juce::Graphics&) override;
    void resized() override;

    void zoomBy (float factor);   // zoomBy(0.8) / zoomBy(1.25)
    void fitWidth();              // fitWidth()

    float getZoom() const noexcept { return zoom; }

    /** Fired whenever the zoom level changes, so the header readout can follow. */
    std::function<void (float)> onZoomChanged;

private:
    void setZoom (float newZoom);
    void applyLayout();

    BlueprintSheet sheet;
    float zoom = 1.0f;
    bool  hasAutoFitted = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SheetViewport)
};