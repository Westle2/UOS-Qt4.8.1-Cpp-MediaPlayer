#include "waveformwidget.h"

WaveformWidget::WaveformWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(100);  // 设置波形区域最小高度
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
    painter.fillRect(rect(), QColor(100, 100, 100));  // 背景黑色
    painter.setPen(Qt::green);           // 波形颜色

    if (audioSamples.isEmpty()) return;

    int width = this->width();
    int height = this->height();
    int centerY = height / 2;
    int sampleCount = audioSamples.size();

    for (int i = 0; i < sampleCount; i += 2)  // 每隔 2 个采样点画一条竖线
    {
        int x = (width * i) / sampleCount;  // 按比例映射 X 轴
        int y = centerY - (audioSamples[i] * centerY / 32768);  // Y 轴映射
        painter.drawLine(x, centerY, x, y);
    }
}
