#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("Hello, Qt on macOS with VS Code!");
    label.show();

    return app.exec();
}
