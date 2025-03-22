//#ifndef RTASRCALLBACKSIMPL_H
//#define RTASRCALLBACKSIMPL_H
//#include "include/sparkchain.h"
//#include "include/sc_raAsr.h"
//#include "include/sc_rtasr.h"

//#include <QDebug>  // 用于调试输出
//#include <QString>
//class MainWindow;
//namespace SparkChain {
//class RtAsrCallbacksImpl
//    : public QObject
//    , public RtAsrCallbacks {
//    Q_OBJECT

//private:
//    MainWindow* mainWindow;  // 存储 MainWindow 指针

//public:
//    explicit RtAsrCallbacksImpl(QObject* parent = nullptr) : QObject(parent) {}
//    explicit RtAsrCallbacksImpl(MainWindow* mainWin) : mainWindow(mainWin) {
//            qDebug() << "RtAsrCallbacksImpl 实例化完成";
//    }
//    ~RtAsrCallbacksImpl();  // 负责清理 SDK 资源
//    void onResult(RtAsrResult* result, void* usrTag) override;
//    void onError(RtAsrError* error, void* usrTag) override;
//    void start_session();  // 开启会话
//    void send_data(const char* data, size_t len);  // 送入音频数据
//    void stop_session();  // 结束会话

//signals:
//    void asrResultReceived(QString text);
//    void asrErrorReceived(QString errMsg);
//};
//}  // namespace SparkChain

//#endif
