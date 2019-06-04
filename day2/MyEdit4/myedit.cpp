#include "myedit.h"
#include <QFileDialog>
#include <QFile>
#include <QByteArray>
#include <QDebug>
#include <QColorDialog>
#include <QFontDialog>

MyEdit::MyEdit(QWidget *parent)
    : QMainWindow(parent)
{
    resize(700, 600);

    init();

    //将菜单添加到菜单栏中
    this->menuBar()->addMenu(m_pFileMenu);
    this->menuBar()->addMenu(m_pEditMenu);
    this->menuBar()->addMenu(m_pHelpMenu);

    m_pCenterTE = new QTextEdit;
    setCentralWidget(m_pCenterTE);

    addToolBar(m_pFileTool);
    addToolBar(m_pEditTool);

    connect(m_pAboutQtAction, SIGNAL(triggered(bool))
            , this, SLOT(aboutQt()));

    connect(m_pOpenAction, SIGNAL(triggered(bool))
            , this, SLOT(openFile()));

    connect(m_pSaveAsAction, SIGNAL(triggered(bool))
            , this, SLOT(saveAs()));

    connect(m_pCopyAction, SIGNAL(triggered(bool))
            , m_pCenterTE, SLOT(copy()));
    connect(m_pPasteAction, SIGNAL(triggered(bool))
            , m_pCenterTE, SLOT(paste()));

    m_pColorAction = new QAction("颜色");
//    m_pColorAction->setIcon();
    m_pEditTool->addAction(m_pColorAction);

    connect(m_pColorAction, SIGNAL(triggered(bool))
            , this, SLOT(setColor()));

    m_pFontAction = new QAction("字体");
//    m_pColorAction->setIcon();
    m_pEditTool->addAction(m_pFontAction);

    connect(m_pFontAction, SIGNAL(triggered(bool))
            , this, SLOT(setFont()));

}

MyEdit::~MyEdit()
{

}

void MyEdit::init()
{
    //产生一个文件菜单
    m_pFileMenu = new QMenu("文件");
    //产生一个菜单上的选项
    m_pOpenAction = new QAction(QIcon(QPixmap(":/map/open.png")), "Open");
    //设置快捷方式
    m_pOpenAction->setShortcut(QKeySequence::Open);
    //设置提示
    m_pOpenAction->setStatusTip("您将要打开一个文件");

    m_pSaveAction = new QAction(QIcon(QPixmap(":/map/save.png")), "SaveFile");
    m_pSaveAction->setShortcut(QKeySequence::Save);
    m_pSaveAction->setStatusTip("您将要保存一个文件");

    m_pSaveAsAction = new QAction("SaveAs");
    m_pSaveAsAction->setShortcut(QKeySequence::SaveAs);
    m_pSaveAsAction->setStatusTip("您将要另保存一个文件");

    m_pCloseAction = new QAction(QIcon(QPixmap(":/map/close.png")), "Close");
    m_pCloseAction->setShortcut(QKeySequence::Close);
    m_pCloseAction->setStatusTip("您将要关闭一个文件");

    m_pExitAction = new QAction(QIcon(QPixmap(":/map/exit.png")), "退出");
    m_pExitAction->setShortcut(QKeySequence::Quit);
    m_pExitAction->setStatusTip("您将要退出程序");

    //将操作选项添加到菜单中
    m_pFileMenu->addAction(m_pOpenAction);
    m_pFileMenu->addAction(m_pSaveAction);
    m_pFileMenu->addAction(m_pSaveAsAction);
    m_pFileMenu->addAction(m_pCloseAction);
    m_pFileMenu->addAction(m_pExitAction);

    m_pFileTool = new QToolBar;
    m_pFileTool->addAction(m_pOpenAction);
    m_pFileTool->addAction(m_pCloseAction);
    m_pFileTool->addAction(m_pSaveAction);
    m_pFileTool->addAction(m_pSaveAsAction);

    /*************************************************/
    m_pEditMenu = new QMenu("编辑");
    m_pCopyAction = new QAction(QIcon(QPixmap(":/map/copy.png")), "Copy");
    m_pCopyAction->setShortcut(QKeySequence::Copy);
    m_pCopyAction->setStatusTip("您将要复制一段内容");

    m_pPasteAction = new QAction(QIcon(QPixmap(":/map/paste.png")), "Paste");
    m_pPasteAction->setShortcut(QKeySequence::Paste);
    m_pPasteAction->setStatusTip("您将要粘贴一段内容");

    m_pCutAction = new QAction(QIcon(QPixmap(":/map/cut.png")), "Cut");
    m_pCutAction->setShortcut(QKeySequence::Cut);
    m_pCutAction->setStatusTip("您将要剪切一段内容");

    m_pUndoAction = new QAction(QIcon(QPixmap(":/map/undo.png")), "Undo");
    m_pUndoAction->setShortcut(QKeySequence::Undo);
    m_pUndoAction->setStatusTip("您将要撤销上次操作");

    //将操作选项添加到菜单中
    m_pEditMenu->addAction(m_pCopyAction);
    m_pEditMenu->addAction(m_pPasteAction);
    m_pEditMenu->addAction(m_pCutAction);
    m_pEditMenu->addAction(m_pUndoAction);

    m_pEditTool = new QToolBar;
    m_pEditTool->addAction(m_pCopyAction);
    m_pEditTool->addAction(m_pPasteAction);
    m_pEditTool->addAction(m_pCutAction);
    m_pEditTool->addAction(m_pUndoAction);


    /***********************************/
    m_pHelpMenu = new QMenu("帮助");
    m_pAboutQtAction = new QAction(QIcon(QPixmap(":/map/aboutqt.png")), "AboutQt");
    m_pAboutQtAction->setStatusTip("关于Qt");
    m_pHelpMenu->addAction(m_pAboutQtAction);

    /*************************************/
    //
    this->statusBar();
}

void MyEdit::aboutQt()
{
    QMessageBox::aboutQt(this, "*^_^*");
}

void MyEdit::openFile()
{
    QString path = QFileDialog::getOpenFileName();
    if (!path.isEmpty())
    {
        QFile file;
        file.setFileName(path);
        file.open(QIODevice::ReadWrite);
        if (file.isOpen())
        {
            //读取打开的文件的内容到字节数组中
            QByteArray data = file.readAll();
            m_pCenterTE->append(data);
            file.close();
        }
    }
}

void MyEdit::saveAs()
{
    //弹出窗口用来指定要保存到那个文件中
    QString path = QFileDialog::getSaveFileName();
    if (!path.isEmpty())
    {
        QFile file(path);
        //以只写的方式打开一个文件
        file.open(QIODevice::WriteOnly);
        //将文本编辑窗口的内容转换成纯文本返回(去掉颜色，字体等)
        QString data = m_pCenterTE->toPlainText();
        //将数据写入文件
        file.write(data.toStdString().c_str(), data.size());
        file.close();

//        m_pCenterTE->document()->isModified();

        int ret = QMessageBox::information(this, "*^_^*", "save as other file ok"
                                 , QMessageBox::Ok, QMessageBox::Cancel);
        if (QMessageBox::Ok == ret)
        {
            qDebug() << "You clicked ok Button";
        }
        else if (QMessageBox::Cancel == ret)
        {
            qDebug() << "You clicked Cancel Button";
        }
        else
        {
            qDebug() << "other clicked";

        }
    }
}

void MyEdit::setColor()
{
    //弹出一个颜色窗口，用来获得一种颜色
    QColor color = QColorDialog::getColor();
    qDebug() << "aaaa";
    //判断获得的颜色是否有效
    if (color.isValid())
    {
        qDebug() << "bbb";
        //设置文本编辑窗口字体的颜色
        //对之前输入的内容不会改变颜色
        m_pCenterTE->setTextColor(color);
    }
}

void MyEdit::setFont()
{
    bool ok;
    //弹出一个字体对话框，ok用来判断是否成功获得一种字体
    QFont font = QFontDialog::getFont(&ok);
    if (ok)
    {
        //设置文本编辑窗口的字体
        m_pCenterTE->setFont(font);
    }
}
