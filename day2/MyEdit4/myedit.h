#ifndef MYEDIT_H
#define MYEDIT_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QTextEdit>
#include <QStatusBar>
#include <QMessageBox>

class MyEdit : public QMainWindow
{
    Q_OBJECT

public:
    MyEdit(QWidget *parent = 0);
    ~MyEdit();
    void init();

public slots:
    void aboutQt();
    void openFile();
    void saveAs();
    void setColor();
    void setFont();

private:
    QMenu *m_pFileMenu;
    QAction *m_pOpenAction;
    QAction *m_pSaveAction;
    QAction *m_pSaveAsAction;
    QAction *m_pCloseAction;
    QAction *m_pExitAction;

    QTextEdit *m_pCenterTE;

    QToolBar *m_pFileTool;

    QMenu *m_pEditMenu;
    QAction *m_pCopyAction;
    QAction *m_pPasteAction;
    QAction *m_pCutAction;
    QAction *m_pUndoAction;

    QToolBar *m_pEditTool;

    QMenu *m_pHelpMenu;
    QAction *m_pAboutQtAction;

    QAction *m_pColorAction;
    QAction *m_pFontAction;

};

#endif // MYEDIT_H
