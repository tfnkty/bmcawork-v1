#ifndef GRAPHPLOT_H
#define GRAPHPLOT_H

#include <QWidget>

class Graphplot : public QWidget
{
    Q_OBJECT

public:
    explicit Graphplot(QWidget *parent = 0);

public slots:
    void setNrOfChannels(int iNrOfChannels);
    void getNrOfChannels(int *piNrOfChannels);
    void setSpectrum(unsigned int *palSpectrum, int iArraySize);
    void getSpectrum(unsigned int *palSpectrum, int iArraySize);
    void ClearSpectrum();

// Member variables
protected:
    int m_iNrOfChannels;
    unsigned int *m_palSpectrum;

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // GRAPHPLOT_H
