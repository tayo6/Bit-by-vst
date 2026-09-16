#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include "GridLayer.h"

/**
    The 1200 × 800 "sheet" — the SVG root of the HTML reference.

    FRACTION 1 owns exactly three layers:

        <rect width="1200" height="800" fill="#f6f6f6"/>          paper
        <rect width="1200" height="800" fill="url(#gs)"/>         20 × 20 grid
        <rect width="1200" height="800" fill="url(#gl)"/>         100 × 100 grid

    Everything else (the double border frame, the dark panel, brand block,
    knob, groove, pipes, VU meters, ruler, dimension lines, title block …)
    is layered on top by the following fractions.

    Zoom is applied by the parent via Component::setTransform, so this
    component always works in the sheet's own logical 1200 × 800 units.
*/
class BlueprintSheet : public juce::Component
{
public:
    BlueprintSheet();

    void paint (juce::Graphics& g) override;

    /** The logical drawing area, in SVG user units. */
    static juce::Rectangle<float> logicalBounds();

private:
    GridLayer fineGrid   { Theme::Metrics::sheetWidth  == 0 ? 20.0f : 20.0f,
                           Theme::Colours::gridFine,   1.0f };
    GridLayer coarseGrid { 100.0f, Theme::Colours::gridCoarse, 1.2f };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BlueprintSheet)
};