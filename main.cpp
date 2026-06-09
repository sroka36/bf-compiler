#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

std::string Compile(std::string input);

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Brainf**k Compiler");
    window.resize(300, 120);

    QVBoxLayout layout(&window);
    QTextEdit input;
    QPushButton button("Compile");
    QLabel result;

    input.setFixedHeight(30);
    input.setMinimumHeight(30);
    QObject::connect(input.document(), &QTextDocument::contentsChanged, [&]() {
        int height = input.document()->size().height() + 10;
        input.setFixedHeight(qMax(30, (int)height));
    });

    layout.addWidget(&input);
    layout.addWidget(&button);
    layout.addWidget(&result);

    

    QObject::connect(&button, &QPushButton::clicked, [&]() {
        std::string output = Compile(input.toPlainText().toStdString());
        result.setText(QString::fromStdString(output));
    });

    window.show();
    return app.exec();
}