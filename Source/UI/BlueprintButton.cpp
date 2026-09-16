#include "BlueprintButton.h"

#include "Theme.h"

BlueprintButton::BlueprintButton (const juce::String& buttonText)
    : juce::Button (buttonText)
{
    setMouseCursor (juce::MouseCursor::PointingHandCursor);
}

int BlueprintButton::getPreferredHeight()
{
    return Theme::buttonHeight();
}

int BlueprintButton::getPreferredWidth() const
{
    const auto font = Theme::monoFont (Theme::Metrics::buttonFontSize);

    // +2px of slack for the right side bearing, which the browser also gets.
    return juce::roundToInt (font.getStringWidthFloat (getButtonText())
                                 + 2.0f * (Theme::Metrics::buttonPadX
                                               + Theme::Metrics::buttonBorder)) + 2;
}

void BlueprintButton::paintButton (juce::Graphics& g,
                                   bool shouldDrawButtonAsHighlighted,
                                   bool shouldDrawButtonAsDown)
{
    // Keep the 1px stroke fully inside the bounds.
    auto r = getLocalBounds().toFloat().reduced (Theme::Metrics::buttonBorder * 0.5f);

    const auto radius = Theme::Metrics::buttonRadius;

    g.setColour (shouldDrawButtonAsHighlighted || shouldDrawButtonAsDown
                     ? Theme::Colours::buttonBgOver
                     : Theme::Colours::buttonBg);
    g.fillRoundedRectangle (r, radius);

    g.setColour (Theme::Colours::buttonEdge);
    g.drawRoundedRectangle (r, radius, Theme::Metrics::buttonBorder);

    g.setColour (Theme::Colours::accent);
    g.setFont (Theme::monoFont (Theme::Metrics::buttonFontSize));
    g.drawText (getButtonText(), getLocalBounds(), juce::Justification::centred, false);
}