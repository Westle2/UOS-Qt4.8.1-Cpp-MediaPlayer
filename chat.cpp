#include "chat.h"
#include "ui_chat.h"

ChatWindow::ChatWindow(QWidget *parent)
    : QDockWidget(parent)
    , ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    // 回车键发送
    connect(ui->inputEdit, &QLineEdit::returnPressed, this, &ChatWindow::on_sendButton_clicked);
    connect(manager, &QNetworkAccessManager::finished, this, &ChatWindow::onReplyFinished);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::appendMessage(const QString &sender, const QString &message)
{
    bool isUser = (sender == "我");  // 判断是不是用户
    addMessage(message, isUser);
}

void ChatWindow::addMessage(const QString &message, bool isUser)
{
    QListWidgetItem *item = new QListWidgetItem;
    QWidget *messageWidget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout(messageWidget);
    layout->setContentsMargins(10, 5, 10, 5);

    QLabel *label = new QLabel(message);
    label->setWordWrap(true);  // 确保文本会换行
    label->setMaximumWidth(500);  // 控制气泡的最大宽度
    label->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    label->setTextInteractionFlags(Qt::TextSelectableByMouse);  // 允许选中文本

    // 设置气泡的样式
    if (isUser) {
        label->setStyleSheet("background-color: lightblue; color: black; border-radius: 10px; padding:5px;");
        layout->addStretch();
        layout->addWidget(label, 0, Qt::AlignRight | Qt::AlignTop);
    } else {
        label->setStyleSheet("background-color: lightgray; color: black; border-radius: 10px; padding:5px;");
        layout->addWidget(label, 0, Qt::AlignLeft | Qt::AlignTop);
        layout->addStretch();
    }

    // 使用 QFontMetrics 计算文本高度
    QFontMetrics fm(label->font());
    int textHeight = fm.height() * label->text().count('\n') + fm.height();

    // 给气泡设置合适的高度
    messageWidget->setFixedHeight(textHeight + 20);  // 加上内边距

    item->setSizeHint(messageWidget->sizeHint());
    messageWidget->setLayout(layout);

    // 添加消息到列表
    ui->chatListWidget->addItem(item);
    ui->chatListWidget->setItemWidget(item, messageWidget);
    ui->chatListWidget->scrollToBottom();
}




void ChatWindow::on_sendButton_clicked()
{
    QString userInput = ui->inputEdit->text().trimmed();
    if (userInput.isEmpty()) return;

    appendMessage("我", userInput);
    ui->inputEdit->clear();
   // lastUserInput = userInput;
    // 构造 JSON 请求
    QJsonObject json;
    json["text"] = userInput;
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    // 设置请求
    QNetworkRequest request(QUrl("http://127.0.0.1:6006/generate"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 异步发送 POST
    manager->post(request, data);
}

void ChatWindow::onReplyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::warning(this, "请求错误", reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray responseData = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    QString replyText;

    if (doc.isObject() && doc.object().contains("generated_text")) {
        replyText = doc.object()["generated_text"].toString();
        replyText.replace("\\n", "\n");

        // // 移除重复的用户输入
        // QString userInput = lastUserInput;  // 需要把 on_sendButton_clicked 的 userInput 存起来
        // if (replyText.startsWith(userInput)) {
        //     replyText = replyText.mid(userInput.length()).trimmed();
        // }
    } else {
        replyText = QString::fromUtf8(responseData);
    }

    appendMessage("机器人", replyText);
    reply->deleteLater();
}
