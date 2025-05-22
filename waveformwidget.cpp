#include "waveformwidget.h"

WaveformWidget::WaveformWidget(QWidget *parent)
    : QWidget(parent)
{
    //setMinimumHeight(100);  // 设置波形区域最小高度
    audioSamples.reserve(500);  // 预分配内存，提高性能
}

void WaveformWidget::setSamples(const QVector<qint16> &samples)
{
    audioSamples = samples;  // 这里统一用 audioSamples
    update();  // 触发重绘
}

void WaveformWidget::appendSamples(const QVector<qint16> &newSamples)
{
    const int maxSamples = 500;  // 控制波形长度
    audioSamples.append(newSamples);

    while (audioSamples.size() > maxSamples) {
        audioSamples.remove(0, audioSamples.size() - maxSamples);
    }

    update();  // 添加数据后，立即更新绘图
}

void WaveformWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    // // 背景渐变（从浅蓝到白）
    // QLinearGradient bgGradient(rect().topLeft(), rect().bottomRight());
    // bgGradient.setColorAt(0, QColor("#e0f7fa")); // 浅蓝
    // bgGradient.setColorAt(1, QColor("#ffffff")); // 白色
    // painter.fillRect(rect(), bgGradient);

    // 设置波形颜色为蓝绿色调
    QPen waveformPen(QColor("#26a69a")); // 柔和青绿色
    waveformPen.setWidth(2);
    painter.setPen(waveformPen);

    if (audioSamples.isEmpty()) return;

    int width = this->width();
    int height = this->height();
    int centerY = height / 2;
    int sampleCount = audioSamples.size();

    for (int i = 0; i < sampleCount; i += 2)
    {
        int x = (width * i) / sampleCount;
        int y = centerY - (audioSamples[i] * centerY / 32768);
        painter.drawLine(x, centerY, x, y);
    }
}

