#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QVariantList>

/**
图像处理
*/
class ImageProcessorPrivate;

class ImageProcessor : public QObject
{
    Q_OBJECT
    Q_ENUMS(ImageAlgorithm)
    Q_PROPERTY(QString sourceFile READ sourceFile)
    Q_PROPERTY(ImageAlgorithm algorithm READ algorithm)

public:
    ImageProcessor(QObject *parent = nullptr);
    ~ImageProcessor();

    enum ImageAlgorithm{
        Gray = 0,
        Binarize,
        Negative,
        Emboss,
        Sharpen,
        Soften,
        AlgorithmCount
    };

    QString sourceFile() const;
    ImageAlgorithm algorithm() const;
    void setTempPath(QString tempPath);

signals:
    void finished(QString newFile);
    void progress(int value);
    void getPixDone(QVariant list);


public slots:
    void process(QString file, ImageAlgorithm algorithm);
    void abort(QString file, ImageAlgorithm algorithm);
    void getPix(QString file, int x, int y);

private:
    ImageProcessorPrivate *m_d;
};

#endif // IMAGEPROCESSOR_H
