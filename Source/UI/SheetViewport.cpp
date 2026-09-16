#include "SheetViewport.h"

#include "Theme.h"

SheetViewport::SheetViewport()
{
    addAndMakeVisible (sheet);
    applyLayout();
}

void SheetViewport::paint (juce::Graphics& g)
{
    g.fillAll (Theme::Colours::pageBg);
}

void SheetViewport::resized()
{
    // The HTML calls fitWidth() once, on load — never again on resize.
    if (! hasAutoFitted && getWidth() > 0)
    {
        hasAutoFitted = true;
        fitWidth();
        return;
    }

    applyLayout();
}

void SheetViewport::applyLayout()
{
    const auto pad = juce::roundToInt (Theme::Metrics::canvasPadding);

    sheet.setBounds (pad, pad,
                     juce::roundToInt (Theme::Metrics::sheetWidth),
                     juce::roundToInt (Theme::Metrics::sheetHeight));

    sheet.setTransform (juce::AffineTransform::scale (zoom));
}

void SheetViewport::setZoom (float newZoom)
{
    // zoom = Math.min(8, Math.max(0.25, zoom))
    zoom = juce::jlimit (Theme::Metrics::zoomMin, Theme::Metrics::zoomMax, newZoom);

    applyLayout();

    if (onZoomChanged != nullptr)
        onZoomChanged (zoom);
}

void SheetViewport::zoomBy (float factor)
{
    setZoom (zoom * factor);
}

void SheetViewport::fitWidth()
{
    // zoom = (box.clientWidth - 48) / 1200
    const auto available = (float) getWidth() - 2.0f * Theme::Metrics::canvasPadding;

    setZoom (available / Theme::Metrics::sheetWidth);
}