#include "BlueprintSheet.h"

#include "Theme.h"

BlueprintSheet::BlueprintSheet()
{
    setInterceptsMouseClicks (false, false);
    setSize (juce::roundToInt (Theme::Metrics::sheetWidth),
             juce::roundToInt (Theme::Metrics::sheetHeight));
}

juce::Rectangle<float> BlueprintSheet::logicalBounds()
{
    return { 0.0f, 0.0f, Theme::Metrics::sheetWidth, Theme::Metrics::sheetHeight };
}

void BlueprintSheet::paint (juce::Graphics& g)
{
    const auto area = getLocalBounds().toFloat();

    // <rect width="1200" height="800" fill="#f6f6f6"/>
    g.fillAll (Theme::Colours::pageBg);

    // <rect width="1200" height="800" fill="url(#gs)"/>
    fineGrid.paint (g, area);

    // <rect width="1200" height="800" fill="url(#gl)"/>
    coarseGrid.paint (g, area);
}