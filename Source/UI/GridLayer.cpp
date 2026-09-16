#include "GridLayer.h"

GridLayer::GridLayer (float cellSize, juce::Colour lineColour, float lineThickness)
    : cell (cellSize), colour (lineColour), thickness (lineThickness)
{
}

void GridLayer::paint (juce::Graphics& g, juce::Rectangle<float> area) const
{
    if (cell <= 0.0f)
        return;

    g.setColour (colour);

    for (float x = area.getX(); x <= area.getRight(); x += cell)
        g.drawLine (x, area.getY(), x, area.getBottom(), thickness);

    for (float y = area.getY(); y <= area.getBottom(); y += cell)
        g.drawLine (area.getX(), y, area.getRight(), y, thickness);
}