#ifndef TOOL_H
#define TOOL_H


#include <QString>

/*!
 * \brief Исполнительный инструмент
 *
 * Класс инсполнительного инструмента (принтрера), содержит в себе настройки имеющие значение для печати
 */

class Tool
{
public:

    explicit Tool();

    /*!
     * \brief Рабочая скорость подачи головки
     * \return Установленная рабочая скорость подачи головки
     * Определяет скорость подачи головки принтера при экструзии пластика
     */
    int feedRate() const;

    /*!
     * \brief Устнановка рабочей скорости  подачи
     * \param Новая рабочая скорость подачи
     */
    void setFeedRate(int newFeedRate);

    /*!
     * \brief Температура экструдера
     * \return Установленная рабочая температура экструдера
     */
    int extruderTemp() const;

    /*!
     * \brief Устнановка рабочей температуры экструдера
     * \param Новая рабочая температура экструдера
     */
    void setExtruderTemp(int newExtruderTemp);

    /*!
     * \brief Рабочая температура платформы
     * \return Установленная рабочая температура платформы
     */
    int platformTemp() const;

    /*!
     * \brief Устнановка рабочей температуры платформы
     * \param Новая рабочая температура платформы
     */
    void setPlatformTemp(int newPlatformTemp);

    /*!
     * \brief Диамерт сопла
     * \return Диаметр установленного сопла
     */
    double nozzleDiameter() const;

    /*!
     * \brief Устнановка диаметра сопла
     * \param Новый диаметра сопла
     */
    void setNozzleDiameter(double newNozzleDiameter);

    /*!
     * \brief Толщина слоя
     * \return Толщина слоя
     */
    double layerHeight() const;

    /*!
     * \brief Устнановка толщины слоя
     * \param Новая толщина слоя
     */
    void setLayerHeight(double newLayerHeight);


protected:
    int m_feedRate;
    int m_extruderTemp;
    int m_platformTemp;
    double m_nozzleDiameter;
    double m_layerHeight;
};

#endif // TOOL_H
