#include "graphplot.h"
#include <QPainter>
#include <iostream>

#include "mlfunc.h"
#include "mlfuncv2.h"

Graphplot::Graphplot(QWidget *parent) : QWidget(parent)
{
    // Init variables
    m_iNrOfChannels = 1024;
    m_palSpectrum = (unsigned int *)malloc(m_iNrOfChannels*sizeof(unsigned int));

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
void Graphplot::setNrOfChannels(int iNrOfChannels)
{
    // Set value
    m_iNrOfChannels = iNrOfChannels;
    // update array
    m_palSpectrum = (unsigned int *)realloc(m_palSpectrum, m_iNrOfChannels*sizeof(unsigned int));
}
void Graphplot::getNrOfChannels(int *piNrOfChannels)
{
   if(piNrOfChannels)
       *piNrOfChannels = m_iNrOfChannels;
}
void Graphplot::setSpectrum(unsigned int *palSpectrum, int iArraySize)
{
    // Determine arraysize
    iArraySize = (iArraySize < m_iNrOfChannels) ? iArraySize : m_iNrOfChannels;

    // Copy spectrum to internal structure
    if(palSpectrum && m_palSpectrum)
       memcpy(m_palSpectrum, palSpectrum, iArraySize*sizeof(unsigned int));

    // redraw
    this->repaint();
}
void Graphplot::getSpectrum(unsigned int *palSpectrum, int iArraySize)
{
    // Determine arraysize
    iArraySize = (iArraySize < m_iNrOfChannels) ? iArraySize : m_iNrOfChannels;

    // Copy spectrum to internal structure
    if(palSpectrum && m_palSpectrum)
        memcpy(palSpectrum, m_palSpectrum, iArraySize*sizeof(unsigned int));
}
void Graphplot::ClearSpectrum()
{
    // Clear array
    if(m_palSpectrum)
       memset(m_palSpectrum, 0, m_iNrOfChannels*sizeof(unsigned int));

    // redraw
    this->repaint();
}
void Graphplot::paintEvent(QPaintEvent *)
{
    int iLastX = 0;
    int iNewX = 0;
    int iLastY = 0;
    int iNewY = 0;
    unsigned int iMaxY = 0;
    float sXScale = 0;
    float sYScale = 0;

    QPainter painter(this);
    //painter.setPen(palette().dark().color());
    painter.setPen(Qt::white);
    painter.setBrush(Qt::NoBrush);
    //painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

    if(!m_palSpectrum)
        return;

    // Get the maximum of the channels counts
    for (int iLoop=0; iLoop < m_iNrOfChannels; iLoop++)
    {
//      if(iLoop < 50)
//            std::cout << iLoop << ", " << m_palSpectrum[iLoop] << std::endl;
        if(m_palSpectrum[iLoop] > iMaxY)
            iMaxY = (int)m_palSpectrum[iLoop] ;
    }

    // SHOULD BE REPLACED WITH REAL DATA
    //arma::mat dummy = { {174, 94.7, 661, 85.1, 0, 0, 0, 0, 0, 0} }; // FOR mlfunc.h
    arma::mat dummy = { {160, 661, 0, 0, 0} }; // FOR mlfuncv2.h
    // SHOULD BE REPLACED WITH REAL DATA
    // REMOVE v2's IN FUNCTION NAMES BELOW IF RUNNING mlfunc.h

    MaterialIDv2(m_palSpectrum); // SEARCHES FOR PEAKS

    IDAlgorithmv2(dummy); // ID ALGORITHM WITHOUT ML
    MLDecisionTreev2(dummy); // WITH ML

    // Round up to next 100
    iMaxY = iMaxY + 100 - (iMaxY % 100);
    // Calculate scale
    sXScale = (float)width()/(float)m_iNrOfChannels;
    sYScale = (float)height()/(float)iMaxY;

    iLastX=0;
    iLastY = height();
    // Go over spectrum
    for (int iLoop=0; iLoop < m_iNrOfChannels; iLoop++)
    {
        iNewX = (int)(((float)iLoop)*sXScale);
        iNewY = (int)(height() - (((float)m_palSpectrum[iLoop]) * sYScale));
        painter.drawLine(iLastX, iLastY, iNewX, iNewY);
        // std::cout << iNewX << ", " << iNewY << std::endl;
        iLastX = iNewX;
        iLastY = iNewY;
    }
    std::cout << "Again" << std::endl;
}
