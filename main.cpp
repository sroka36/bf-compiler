#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

std::string Compile(std::string input);

int main(int argc, char *argv[]) {
    //app 초기화
    QApplication app(argc, argv);

    //창 설정
    QWidget window;
    window.setWindowTitle("Brainf**k Compiler");
    window.resize(300, 120);

    //레이아웃 설정
    QVBoxLayout layout(&window);

    //위젯 정의
    QTextEdit input;
    QPushButton button("Compile");
    QLabel result;

    //가변 입력창 만들기(최소 높이 30)
    input.setFixedHeight(30);
    QObject::connect(input.document(), &QTextDocument::contentsChanged, [&]() {
        int height = input.document() -> size().height() + 10;
        input.setFixedHeight(qMax(30, (int)height));
    });

    //위젯 추가
    layout.addWidget(&input);
    layout.addWidget(&button);
    layout.addWidget(&result);

    //컴파일
    QObject::connect(&button, &QPushButton::clicked, [&]() {
        std::string output = Compile(input.toPlainText().toStdString());
        result.setText(QString::fromStdString(output));
    });

    //창 보여주기
    window.show();
    return app.exec();
}