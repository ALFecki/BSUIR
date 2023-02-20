namespace lab_1;

public partial class App : Application {
    public App() {
        InitializeComponent();

        MainPage = new AppShell();
    }

    protected override Window CreateWindow(IActivationState activationState) {
        var window = base.CreateWindow(activationState);
        const int width = 460;
        const int height = 740;
        window.Width = width;
        window.Height = height;
        window.MaximumWidth = width;
        window.MaximumHeight = height;
        window.MinimumWidth = width;
        window.MinimumHeight = height;
        return window;
    }
}
