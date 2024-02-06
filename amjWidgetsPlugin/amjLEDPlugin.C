#include <amjWidgets.H>
#include "amjLEDPlugin.H"

#include <QtPlugin>
#include <QtDesigner/QDesignerFormEditorInterface>

amjLEDPlugin::amjLEDPlugin(QObject *parent)
  : QObject(parent)
{
  m_initialized = false;
}

void amjLEDPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
  if (m_initialized)
    return;

  // Add extension registrations, etc. here

  m_initialized = true;
}

bool amjLEDPlugin::isInitialized() const
{
  return m_initialized;
}

QWidget *amjLEDPlugin::createWidget(QWidget *parent)
{
  return new amjLED(parent);
}

QString amjLEDPlugin::name() const
{
  return QLatin1String("amjLED");
}

QString amjLEDPlugin::group() const
{
  return QLatin1String("amjWidgets");
}

QIcon amjLEDPlugin::icon() const
{
  return QIcon();
}

QString amjLEDPlugin::toolTip() const
{
  return QLatin1String("");
}

QString amjLEDPlugin::whatsThis() const
{
  return QLatin1String("");
}

bool amjLEDPlugin::isContainer() const
{
  return false;
}

QString amjLEDPlugin::domXml() const
{
  //  return QLatin1String("<widget class=\"amjLED\" name=\"amjLED\">");
  return QLatin1String("<widget class=\"amjLED\" name=\"amjLED\"/>");
}

QString amjLEDPlugin::includeFile() const
{
  return QLatin1String("amjWidgets.H");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(amjledplugin, amjLEDPlugin)
#endif // QT_VERSION < 0x050000
