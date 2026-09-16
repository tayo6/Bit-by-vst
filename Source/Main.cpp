#include <juce_gui_extra/juce_gui_extra.h>

#include "MainComponent.h"
#include "UI/Theme.h"

class HuhBlueprintApplication : public juce::JUCEApplication
{
public:
    HuhBlueprintApplication() = default;

    const juce::String getApplicationName()    override { return "HUH Blueprint"; }
    const juce::String getApplicationVersion() override { return "0.1.0"; }
    bool moreThanOneInstanceAllowed()          override { return true; }

    void initialise (const juce::String&) override
    {
        mainWindow = std::make_unique<MainWindow> (getApplicationName());
    }

    void shutdown() override
    {
        mainWindow = nullptr;
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    //==========================================================================
    class MainWindow : public juce::DocumentWindow
    {
    public:
        explicit MainWindow (const juce::String& name)
            : DocumentWindow (name,
                              Theme::Colours::pageBg,
                              DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainComponent(), true);
            setResizable (true, false);
            setResizeLimits (640, 480, 10000, 10000);
            centreWithSize (getWidth(), getHeight());
            setVisible (true);
        }

        void closeButtonPressed() override
        {
            juce::JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION (HuhBlueprintApplication)