#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include <QDockWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QLabel>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatWindow; }
QT_END_NAMESPACE

class ChatWindow : public QDockWidget
{
    Q_OBJECT

public:
    ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void on_sendButton_clicked();
    void onReplyFinished(QNetworkReply *reply);

private:
    Ui::ChatWindow *ui;
    QNetworkAccessManager *manager;
    QString lastUserInput;   // 保存上次用户输入
    void appendMessage(const QString &sender, const QString &message);
    void addMessage(const QString &message, bool isUser);
};


#endif // CHAT_H
