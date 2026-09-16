#include "MainComponent.h"

#include "UI/Theme.h"

MainComponent::MainComponent()
{
    addAndMakeVisible (header);
    addAndMakeVisible (viewport);

    // ---- header → canvas ------------------------------------------------
    header.onZoomOut  = [this] { viewport.zoomBy (0.8f);  };
    header.onZoomIn   = [this] { viewport.zoomBy (1.25f); };
    header.onFitWidth = [this] { viewport.fitWidth();     };

    header.onDownloadSvg = [this]
    {
        // FRACTION 1 has no vector payload to export yet — the sheet artwork
        // (frame, panel, brand block, knob, groove, pipes, VU, ruler, title
        // block …) lands in the following fractions.
        //
        // Once every layer exposes a juce::Path, this will serialise them to a
        // real .svg and hand it to the OS, matching downloadSVG() in the HTML.
        juce::Logger::writeToLog ("DOWNLOAD SVG: no vector payload yet (fraction 1)");
    };

    // ---- canvas → header ------------------------------------------------
    viewport.onZoomChanged = [this] (float zoom) { header.setZoomLevel (zoom); };

    setSize (1280, 900);
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (Theme::Colours::pageBg);
}

void MainComponent::resized()
{
    auto r = getLocalBounds();

    header  .setBounds (r.removeFromTop (Theme::headerHeight()));
    viewport.setBounds (r);
}