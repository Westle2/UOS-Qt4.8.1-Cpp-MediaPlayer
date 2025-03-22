//class MainWindow;
//#include "mainwindow.h"
//#include "RtAsrCallbacksImpl.h"
//using namespace SparkChain;

//RtAsrCallbacksImpl::~RtAsrCallbacksImpl() {
//    qDebug() << "RtAsrCallbacksImpl 释放资源";
//    SparkChain::unInit();  // 逆初始化 SDK
//}

//void RtAsrCallbacksImpl::onResult(RtAsrResult* result, void* usrTag) {
//    if (!result) {
//        qDebug() << "No result received.";
//        return;
//    }

//    // 获取数据
//    int status = result->status();  // 数据状态
//    QString sid = QString::fromStdString(result->sid());  // sid
//    QString rawResult = QString::fromStdString(result->rawResult());  // 原始结果
//    QString data = QString::fromStdString(result->data());  // 转写结果
//    QString src = QString::fromStdString(result->transResult()->src());  // 翻译源文本
//    QString dst = QString::fromStdString(result->transResult()->dst());  // 翻译结果

//    // 输出调试信息
//    qDebug() << "ASR Result: status =" << status << ", sid =" << sid;
////    qDebug() << "Raw JSON:" << rawResult;
//    qDebug() << "Text:" << data;
//    //qDebug() << "Translation:" << src << " -> " << dst;
////    if (status == 0) {
////        // 仅当状态为0时才是最终结果
////        QString resultText = QString::fromStdString(result->data());
////        qDebug() << "Final Recognition Result: " << resultText;
////    } else {
////        qDebug() << "Partial result: " << QString::fromStdString(result->data());
////    }
//    // 触发信号
//    emit mainWindow->asrResultReceived(data);
//}

//void RtAsrCallbacksImpl::onError(RtAsrError* error, void* usrTag) {
//    if (!error) {
//        qDebug() << "No error received.";
//        return;
//    }

//    QString sid = QString::fromStdString(error->sid());  // 获取sid
//    int code = error->code();  // 错误码
//    QString errMsg = QString::fromStdString(error->errMsg());  // 错误信息

//    // 输出调试信息
//    qDebug() << "ASR Error: sid =" << sid << ", code =" << code;
//    qDebug() << "Error Message:" << errMsg;
//    emit mainWindow->asrResultReceived(errMsg);
//}
