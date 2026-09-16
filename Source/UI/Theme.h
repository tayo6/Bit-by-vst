#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

/**
    Single source of truth for the HUH blueprint look.

    Every value below is lifted 1:1 from the HTML/CSS reference sheet so the
    JUCE build and the browser build stay identical. When the HTML changes,
    change it here and nowhere else.
*/
namespace Theme
{
    //==========================================================================
    namespace Colours
    {
        inline const juce::Colour pageBg       { 0xfff6f6f6 }; // body background + sheet paper
        inline const juce::Colour ink          { 0xff2e2f2f }; // body color
        inline const juce::Colour accent       { 0xff4a7ba6 }; // h1 colour + button text
        inline const juce::Colour hairline     { 0xffb7d3ee }; // header border-bottom
        inline const juce::Colour gridFine     { 0xffd9e7f5 }; // SVG pattern  #gs   (20 × 20)
        inline const juce::Colour gridCoarse   { 0xffb7d3ee }; // SVG pattern  #gl   (100 × 100)
        inline const juce::Colour buttonBg     { 0xffeaf2fa };
        inline const juce::Colour buttonBgOver { 0xffdcebf7 }; // :hover
        inline const juce::Colour buttonEdge   { 0xff7fb2d9 };
    }

    //==========================================================================
    namespace Metrics
    {
        // ---- header ---------------------------------------------------------
        constexpr float headerPadX     = 16.0f;  // padding: 10px 16px
        constexpr float headerPadY     = 10.0f;
        constexpr float headerGap      = 10.0f;  // flex `gap`
        constexpr float titleGap       = 16.0f;  // h1 margin-right
        constexpr float titleFontSize  = 14.0f;
        constexpr float titleTracking  = 3.0f;   // letter-spacing: 3px
        constexpr float hairlineWidth  = 1.0f;

        // ---- buttons --------------------------------------------------------
        constexpr float buttonFontSize = 13.33f; // UA default for <button>
        constexpr float buttonPadX     = 12.0f;  // padding: 6px 12px
        constexpr float buttonPadY     = 6.0f;
        constexpr float buttonRadius   = 6.0f;   // border-radius: 6px
        constexpr float buttonBorder   = 1.0f;

        // ---- zoom readout ---------------------------------------------------
        // #zl inherits body's 16px (body declares no font-size of its own).
        constexpr float zoomReadoutFontSize = 16.0f;
        constexpr float zoomReadoutMinWidth = 52.0f;

        // ---- canvas ---------------------------------------------------------
        constexpr float canvasPadding = 24.0f;   // main { padding: 24px }
        constexpr float sheetWidth    = 1200.0f; // SVG viewBox
        constexpr float sheetHeight   = 800.0f;

        constexpr float zoomMin = 0.25f;
        constexpr float zoomMax = 8.0f;
    }

    //==========================================================================
    /** Consolas → Courier New → system monospaced, matching
        `font-family: Consolas, 'Courier New', monospace`. */
    inline const juce::String& monoTypeface()
    {
        static const juce::String resolved = []
        {
            const auto installed = juce::Font::findAllTypefaceNames();

            for (const auto* candidate : { "Consolas", "Courier New" })
                if (installed.contains (candidate))
                    return juce::String (candidate);

            return juce::Font::getDefaultMonospacedFontName();
        }();

        return resolved;
    }

    inline juce::Font monoFont (float height)
    {
        return juce::Font (monoTypeface(), height, juce::Font::plain);
    }

    /** `header h1 { font-size:14px; letter-spacing:3px }` */
    inline juce::Font titleFont()
    {
        return monoFont (Metrics::titleFontSize)
                   .withExtraKerningFactor (Metrics::titleTracking / Metrics::titleFontSize);
    }

    /** Height of one button: 2×(6px padding + 1px border) + one line of text. */
    inline int buttonHeight()
    {
        return juce::roundToInt (2.0f * (Metrics::buttonPadY + Metrics::buttonBorder)
                                     + monoFont (Metrics::buttonFontSize).getHeight());
    }

    /** Total header height: 10 + button + 10 + 1px hairline (content-box). */
    inline int headerHeight()
    {
        return juce::roundToInt (2.0f * Metrics::headerPadY
                                     + (float) buttonHeight()
                                     + Metrics::hairlineWidth);
    }
}