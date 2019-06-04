#include "myedit.h"

MyEdit::MyEdit(QWidget *parent)
    : QMainWindow(parent)
{
    init();

    this->menuBar()->addMenu(m_pFileMenu);
}

MyEdit::~MyEdit()
{

}

void MyEdit::init()
{
    m_pFileMenu = new QMenu("文件");
    m_pOpenAction = new QAction(QIcon(QPixmap(":/map/open.png")), "Open");
    m_pOpenAction->setShortcut(QKeySequence::Open);
    m_pOpenAction->setStatusTip("您将要打开一个文件");

    m_pSaveAction = new QAction(QIcon(QPixmap(":/map/save.png")), "SaveFile");
    m_pSaveAction->setShortcut(QKeySequence::Save);
    m_pSaveAction->setStatusTip("您将要保存一个文件");

    m_pFileMenu->addAction(m_pOpenAction);
    m_pFileMenu->addAction(m_pSaveAction);

//    QAction *m_pSaveAsAction;
//    QAction *m_pCloseAction;
//    QAction *m_pExitAction;
}
