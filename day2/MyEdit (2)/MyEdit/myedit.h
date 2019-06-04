#ifndef MYEDIT_H
#define MYEDIT_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QTextEdit>

class MyEdit : public QMainWindow
{
    Q_OBJECT

public:
    MyEdit(QWidget *parent = 0);
    ~MyEdit();
    void init();

private:
    QMenu *m_pFileMenu;
    QAction *m_pOpenAction;
    QAction *m_pSaveAction;
    QAction *m_pSaveAsAction;
    QAction *m_pCloseAction;
    QAction *m_pExitAction;

    QTextEdit *m_pCenterTE;

    QToolBar *m_pFileTool;

//    QMenu *m_pEditMenu;
//    QAction *m_pCopyAction;
//    QAction *m_pSaveAction;
//    QAction *m_pSaveAsAction;
//    QAction *m_pCloseAction;
//    QAction *m_pExitAction;

//    QToolBar *m_pFileTool;

};

#endif // MYEDIT_H
