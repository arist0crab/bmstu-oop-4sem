TEMPLATE = app
TARGET = Frame3DViewer
QT += core widgets gui

# Папки проекта
HEADERS_DIR = headers
SOURCES_DIR = sources
FORMS_DIR = forms

# Пути для компиляции
INCLUDEPATH += $$HEADERS_DIR
UI_DIR = $$FORMS_DIR

# Файлы проекта
SOURCES += $$files($$SOURCES_DIR/*.cpp)
HEADERS += $$files($$HEADERS_DIR/*.h)
FORMS += $$files($$FORMS_DIR/*.ui)

# Папка для сборки
DESTDIR = build
OBJECTS_DIR = build/obj
MOC_DIR = build/moc