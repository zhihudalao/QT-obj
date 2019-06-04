#include "videosurface.h"

videosurface::videosurface(QObject *parent)
    : QAbstractVideoSurface(parent)
{

}


bool videosurface::present(const QVideoFrame &frame)
{
    emit frameChanged(frame);
}

QList<QVideoFrame::PixelFormat>
videosurface::supportedPixelFormats(
        QAbstractVideoBuffer::HandleType type) const
{
    return QList<QVideoFrame::PixelFormat>()
            << QVideoFrame::Format_RGB32;
}
