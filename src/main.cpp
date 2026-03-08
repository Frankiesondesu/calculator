#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFont>

class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Calculator");
        setFixedSize(320, 420);

        auto *layout = new QVBoxLayout(this);
        layout->setSpacing(10);
        layout->setContentsMargins(10, 10, 10, 10);

        // Display
        display = new QLineEdit();
        display->setReadOnly(true);
        display->setAlignment(Qt::AlignRight);
        display->setFont(QFont("Arial", 20, QFont::Bold));
        display->setFixedHeight(60);
        layout->addWidget(display);

        // Buttons grid
        auto *gridLayout = new QGridLayout();
        gridLayout->setSpacing(8);

        QStringList buttonLabels = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+",
            "C"
        };

        int row = 0;
        int col = 0;

        for (const QString &label : buttonLabels) {
            QPushButton *button = new QPushButton(label);
            button->setFont(QFont("Arial", 16, QFont::Bold));
            button->setFixedHeight(60);
            
            if (label == "=") {
                button->setStyleSheet("background-color: #4CAF50; color: white;");
                connect(button, &QPushButton::clicked, this, &Calculator::calculate);
            } else if (label == "C") {
                button->setStyleSheet("background-color: #f44336; color: white;");
                connect(button, &QPushButton::clicked, this, &Calculator::clear);
            } else {
                button->setStyleSheet("background-color: #e0e0e0;");
                connect(button, &QPushButton::clicked, this, [this, label]() {
                    appendToDisplay(label);
                });
            }

            if (label == "C") {
                gridLayout->addWidget(button, 4, 0, 1, 4);
            } else {
                gridLayout->addWidget(button, row, col);
                col++;
                if (col > 3) {
                    col = 0;
                    row++;
                }
            }
        }

        layout->addLayout(gridLayout);
    }

private slots:
    void appendToDisplay(const QString &text) {
        display->setText(display->text() + text);
    }

    void clear() {
        display->clear();
    }

    void calculate() {
        QString expression = display->text();
        
        // Simple evaluation (for basic operations)
        double result = 0;
        QStringList tokens;
        QString currentToken;
        
        for (int i = 0; i < expression.length(); i++) {
            QChar ch = expression[i];
            if (ch.isDigit() || ch == '.') {
                currentToken += ch;
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (!currentToken.isEmpty()) {
                    tokens << currentToken;
                    currentToken.clear();
                }
                tokens << QString(ch);
            }
        }
        if (!currentToken.isEmpty()) {
            tokens << currentToken;
        }

        if (tokens.isEmpty()) return;

        // Parse first number
        int idx = 0;
        result = tokens[idx++].toDouble();

        while (idx < tokens.size()) {
            if (idx >= tokens.size()) break;
            QString op = tokens[idx++];
            if (idx >= tokens.size()) break;
            double num = tokens[idx++].toDouble();

            if (op == "+") {
                result += num;
            } else if (op == "-") {
                result -= num;
            } else if (op == "*") {
                result *= num;
            } else if (op == "/") {
                if (num != 0) {
                    result /= num;
                } else {
                    display->setText("Error");
                    return;
                }
            }
        }

        display->setText(QString::number(result));
    }

private:
    QLineEdit *display;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    Calculator calc;
    calc.show();
    
    return app.exec();
}
