#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

/**
    One tiled grid background — the direct JUCE equivalent of an SVG <pattern>.

    The HTML patterns are:

        <pattern id="gs" width="20"  height="20">  <path d="M20,0  H0 V20"/>
        <pattern id="gl" width="100" height="100"> <path d="M100,0 H0 V100"/>

    i.e. the top and left edge of every cell, which is what produces a
    continuous grid when tiled. This class draws exactly that.

    Deliberately *not* a juce::Component: it is a pure painter so the sheet can
    stack several of them inside a single paint() pass and share one transform.
*/
class GridLayer
{
public:
    GridLayer (float cellSize, juce::Colour lineColour, float lineThickness);

    /** Paints the grid over `area`, in the caller's current coordinate space. */
    void paint (juce::Graphics& g, juce::Rectangle<float> area) const;

private:
    float        cell;
    juce::Colour colour;
    float        thickness;
};