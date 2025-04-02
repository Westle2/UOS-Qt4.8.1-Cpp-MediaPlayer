#ifndef WAVEFORMWIDGET_H
#define WAVEFORMWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QVector>

class WaveformWidget : public QWidget
{
    Q_OBJECT
private:
    QVector<qint16> audioSamples;
public:
    explicit WaveformWidget(QWidget *parent = nullptr);
    void setSamples(const QVector<qint16> &samples);  // 新增接口
    void appendSamples(const QVector<qint16> &newSamples);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // WAVEFORMWIDGET_H
