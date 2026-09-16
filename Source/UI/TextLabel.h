#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

/**
    A passive single-line text block — the JUCE stand-in for the CSS <h1>
    and the <span id="zl"> zoom readout.
*/
class TextLabel : public juce::Component
{
public:
    TextLabel (juce::String labelText,
               juce::Font   labelFont,
               juce::Colour labelColour,
               juce::Justification labelJustification = juce::Justification::centredLeft)
        : text (std::move (labelText)),
          font (labelFont),
          colour (labelColour),
          justification (labelJustification)
    {
        setInterceptsMouseClicks (false, false);
    }

    void setText (const juce::String& newText)
    {
        if (text != newText)
        {
            text = newText;
            repaint();
        }
    }

    const juce::String& getText() const noexcept { return text; }

    /** Natural width of the string in the current font (+2px slack). */
    int getPreferredWidth() const
    {
        return juce::roundToInt (font.getStringWidthFloat (text)) + 2;
    }

    void paint (juce::Graphics& g) override
    {
        g.setColour (colour);
        g.setFont (font);
        g.drawText (text, getLocalBounds(), justification, false);
    }

private:
    juce::String        text;
    juce::Font          font;
    juce::Colour        colour;
    juce::Justification justification;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TextLabel)
};