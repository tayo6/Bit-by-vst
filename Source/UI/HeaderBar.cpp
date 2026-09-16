#include "HeaderBar.h"

namespace
{
    // U+2212 MINUS SIGN — exactly the character the HTML button uses.
    constexpr juce_wchar minusSign = 0x2212;
}

HeaderBar::HeaderBar()
    : title          (juce::String::fromUTF8 ("HUH \xc2\xb7 BLUEPRINT PREVIEW"),
                      Theme::titleFont(),
                      Theme::Colours::accent,
                      juce::Justification::centredLeft),
      zoomReadout    ("100%",
                      Theme::monoFont (Theme::Metrics::zoomReadoutFontSize),
                      Theme::Colours::accent,
                      juce::Justification::centred),
      zoomOutButton  (juce::String::charToString (minusSign)),
      zoomInButton   ("+"),
      fitButton      ("FIT"),
      downloadButton ("DOWNLOAD SVG")
{
    addAndMakeVisible (title);
    addAndMakeVisible (zoomReadout);
    addAndMakeVisible (zoomOutButton);
    addAndMakeVisible (zoomInButton);
    addAndMakeVisible (fitButton);
    addAndMakeVisible (downloadButton);

    zoomOutButton .onClick = [this] { if (onZoomOut)     onZoomOut();     };
    zoomInButton  .onClick = [this] { if (onZoomIn)      onZoomIn();      };
    fitButton     .onClick = [this] { if (onFitWidth)    onFitWidth();    };
    downloadButton.onClick = [this] { if (onDownloadSvg) onDownloadSvg(); };
}

void HeaderBar::paint (juce::Graphics& g)
{
    g.fillAll (Theme::Colours::pageBg);

    // border-bottom: 1px solid #b7d3ee
    g.setColour (Theme::Colours::hairline);
    g.fillRect (0.0f,
                (float) getHeight() - Theme::Metrics::hairlineWidth,
                (float) getWidth(),
                Theme::Metrics::hairlineWidth);
}

void HeaderBar::resized()
{
    auto r = getLocalBounds();

    r.removeFromBottom (juce::roundToInt (Theme::Metrics::hairlineWidth));
    r = r.reduced (juce::roundToInt (Theme::Metrics::headerPadX),
                   juce::roundToInt (Theme::Metrics::headerPadY));

    // align-items: center
    r = r.withSizeKeepingCentre (r.getWidth(), Theme::buttonHeight());

    const auto gap      = juce::roundToInt (Theme::Metrics::headerGap);
    const auto titleGap = juce::roundToInt (Theme::Metrics::titleGap);

    title.setBounds (r.removeFromLeft (title.getPreferredWidth()));
    r.removeFromLeft (titleGap);

    zoomOutButton.setBounds (r.removeFromLeft (zoomOutButton.getPreferredWidth()));
    r.removeFromLeft (gap);

    zoomReadout.setBounds (r.removeFromLeft (juce::roundToInt (Theme::Metrics::zoomReadoutMinWidth)));
    r.removeFromLeft (gap);

    zoomInButton.setBounds (r.removeFromLeft (zoomInButton.getPreferredWidth()));
    r.removeFromLeft (gap);

    fitButton.setBounds (r.removeFromLeft (fitButton.getPreferredWidth()));
    r.removeFromLeft (gap);

    downloadButton.setBounds (r.removeFromLeft (downloadButton.getPreferredWidth()));
}

void HeaderBar::setZoomLevel (float zoom)
{
    zoomReadout.setText (juce::String (juce::roundToInt (zoom * 100.0f)) + "%");
}