#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void newFile();
//    void open();
//    void save();
//    void print();
//    void undo();
//    void redo();
//    void cut();
//    void copy();
//    void paste();
//    void bold();
//    void italic();
//    void leftAlign();
//    void rightAlign();
//    void justify();
//    void center();
//    void setLineSpacing();
//    void setParagraphSpacing();
//    void about();
//    void aboutQt();

private:
    void createAction();
    void createMenus();

private:
    std::unique_ptr<QMenu> _fileMenu;
    std::unique_ptr<QMenu> _editMenu;
    std::unique_ptr<QMenu> _formatMenu;
    std::unique_ptr<QMenu> _helpMenu;
    std::unique_ptr<QAction> _newAction;
    std::unique_ptr<QAction> _openAction;
    std::unique_ptr<QAction> _saveAction;
    std::unique_ptr<QAction> _printAction;
    std::unique_ptr<QAction> _exitAction;
    std::unique_ptr<QAction> _undoAction;
    std::unique_ptr<QAction> _redoAction;
    std::unique_ptr<QAction> _cutAction;
    std::unique_ptr<QAction> _copyAction;
    std::unique_ptr<QAction> _pasteAction;
    std::unique_ptr<QAction> _boldAction;
    std::unique_ptr<QAction> _italicAction;
    std::unique_ptr<QActionGroup> _alignmentGroup;
    std::unique_ptr<QAction> _leftAlignAction;
    std::unique_ptr<QAction> _rightAlignAction;
    std::unique_ptr<QAction> _justifyAction;
    std::unique_ptr<QAction> _centerAction;
    std::unique_ptr<QAction> _setLineSpacingAction;
    std::unique_ptr<QAction> _setParagraphSpacingAction;
    std::unique_ptr<QAction> _aboutAction;
    std::unique_ptr<QAction> _aboutQtAction;
    std::unique_ptr<QLabel> _infoLabel;
};
#endif // MAINWINDOW_H
