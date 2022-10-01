/********************************************************************************
** Form generated from reading UI file 'a11.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A11_H
#define UI_A11_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_a11Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *exceptionLabel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QListWidget *adminList;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QVBoxLayout *verticalLayout;
    QLineEdit *originalEdit;
    QLineEdit *newTitleEdit;
    QLineEdit *presenterEdit;
    QLineEdit *minutesEdit;
    QLineEdit *secondsEdit;
    QLineEdit *likesEdit;
    QLineEdit *linkEdit;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QListWidget *userList;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *seeTutorialsButton;
    QLineEdit *presenterNameEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addTutorialButton;
    QPushButton *nextButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *deleteTutorialButton;
    QLineEdit *deleteTutorialEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *ignoreTutorialButton;
    QPushButton *likeTutorialButton;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_11;
    QPushButton *CSV;
    QPushButton *HTML;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *a11Class)
    {
        if (a11Class->objectName().isEmpty())
            a11Class->setObjectName(QString::fromUtf8("a11Class"));
        a11Class->resize(952, 636);
        centralWidget = new QWidget(a11Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        exceptionLabel = new QLabel(centralWidget);
        exceptionLabel->setObjectName(QString::fromUtf8("exceptionLabel"));

        verticalLayout_6->addWidget(exceptionLabel);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_9->addWidget(label, 0, Qt::AlignHCenter);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2, 0, Qt::AlignHCenter);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        adminList = new QListWidget(centralWidget);
        adminList->setObjectName(QString::fromUtf8("adminList"));

        verticalLayout_3->addWidget(adminList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout_3->addWidget(addButton);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout_3->addWidget(deleteButton);

        updateButton = new QPushButton(centralWidget);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        horizontalLayout_3->addWidget(updateButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_2->addWidget(label_10);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        originalEdit = new QLineEdit(centralWidget);
        originalEdit->setObjectName(QString::fromUtf8("originalEdit"));

        verticalLayout->addWidget(originalEdit);

        newTitleEdit = new QLineEdit(centralWidget);
        newTitleEdit->setObjectName(QString::fromUtf8("newTitleEdit"));

        verticalLayout->addWidget(newTitleEdit);

        presenterEdit = new QLineEdit(centralWidget);
        presenterEdit->setObjectName(QString::fromUtf8("presenterEdit"));

        verticalLayout->addWidget(presenterEdit);

        minutesEdit = new QLineEdit(centralWidget);
        minutesEdit->setObjectName(QString::fromUtf8("minutesEdit"));

        verticalLayout->addWidget(minutesEdit);

        secondsEdit = new QLineEdit(centralWidget);
        secondsEdit->setObjectName(QString::fromUtf8("secondsEdit"));

        verticalLayout->addWidget(secondsEdit);

        likesEdit = new QLineEdit(centralWidget);
        likesEdit->setObjectName(QString::fromUtf8("likesEdit"));

        verticalLayout->addWidget(likesEdit);

        linkEdit = new QLineEdit(centralWidget);
        linkEdit->setObjectName(QString::fromUtf8("linkEdit"));

        verticalLayout->addWidget(linkEdit);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_4 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        userList = new QListWidget(centralWidget);
        userList->setObjectName(QString::fromUtf8("userList"));

        verticalLayout_5->addWidget(userList);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        seeTutorialsButton = new QPushButton(centralWidget);
        seeTutorialsButton->setObjectName(QString::fromUtf8("seeTutorialsButton"));

        horizontalLayout_4->addWidget(seeTutorialsButton);

        presenterNameEdit = new QLineEdit(centralWidget);
        presenterNameEdit->setObjectName(QString::fromUtf8("presenterNameEdit"));

        horizontalLayout_4->addWidget(presenterNameEdit);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        addTutorialButton = new QPushButton(centralWidget);
        addTutorialButton->setObjectName(QString::fromUtf8("addTutorialButton"));

        horizontalLayout_5->addWidget(addTutorialButton);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout_5->addWidget(nextButton);


        verticalLayout_5->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        deleteTutorialButton = new QPushButton(centralWidget);
        deleteTutorialButton->setObjectName(QString::fromUtf8("deleteTutorialButton"));

        horizontalLayout_7->addWidget(deleteTutorialButton);

        deleteTutorialEdit = new QLineEdit(centralWidget);
        deleteTutorialEdit->setObjectName(QString::fromUtf8("deleteTutorialEdit"));

        horizontalLayout_7->addWidget(deleteTutorialEdit);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ignoreTutorialButton = new QPushButton(centralWidget);
        ignoreTutorialButton->setObjectName(QString::fromUtf8("ignoreTutorialButton"));

        horizontalLayout_6->addWidget(ignoreTutorialButton);

        likeTutorialButton = new QPushButton(centralWidget);
        likeTutorialButton->setObjectName(QString::fromUtf8("likeTutorialButton"));

        horizontalLayout_6->addWidget(likeTutorialButton);


        verticalLayout_5->addLayout(horizontalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_4->addWidget(label_11, 0, Qt::AlignHCenter);

        CSV = new QPushButton(centralWidget);
        CSV->setObjectName(QString::fromUtf8("CSV"));

        verticalLayout_4->addWidget(CSV);

        HTML = new QPushButton(centralWidget);
        HTML->setObjectName(QString::fromUtf8("HTML"));

        verticalLayout_4->addWidget(HTML);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_4->addWidget(label_12, 0, Qt::AlignHCenter);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_8->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);

        a11Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(a11Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 952, 22));
        a11Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(a11Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        a11Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(a11Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        a11Class->setStatusBar(statusBar);

        retranslateUi(a11Class);

        QMetaObject::connectSlotsByName(a11Class);
    } // setupUi

    void retranslateUi(QMainWindow *a11Class)
    {
        a11Class->setWindowTitle(QCoreApplication::translate("a11Class", "a11", nullptr));
        exceptionLabel->setText(QCoreApplication::translate("a11Class", "Exception:", nullptr));
        label->setText(QCoreApplication::translate("a11Class", "ADMIN", nullptr));
        label_2->setText(QCoreApplication::translate("a11Class", "USER", nullptr));
        addButton->setText(QCoreApplication::translate("a11Class", "ADD TUTORIAL", nullptr));
        deleteButton->setText(QCoreApplication::translate("a11Class", "DELETE TUTORIAL BY TITLE", nullptr));
        updateButton->setText(QCoreApplication::translate("a11Class", "UPDATE TUTORIAL", nullptr));
        label_10->setText(QCoreApplication::translate("a11Class", "ORIGINAL TITLE", nullptr));
        label_3->setText(QCoreApplication::translate("a11Class", "NEW TITLE", nullptr));
        label_4->setText(QCoreApplication::translate("a11Class", "PRESENTER", nullptr));
        label_5->setText(QCoreApplication::translate("a11Class", "MINUTES", nullptr));
        label_6->setText(QCoreApplication::translate("a11Class", "SECONDS", nullptr));
        label_7->setText(QCoreApplication::translate("a11Class", "LIKES", nullptr));
        label_8->setText(QCoreApplication::translate("a11Class", "LINK", nullptr));
        seeTutorialsButton->setText(QCoreApplication::translate("a11Class", "SEE TUTORIALS BY PRESENTER", nullptr));
        presenterNameEdit->setText(QString());
        addTutorialButton->setText(QCoreApplication::translate("a11Class", "ADD TUTORIAL", nullptr));
        nextButton->setText(QCoreApplication::translate("a11Class", "SKIP TUTORIAL", nullptr));
        deleteTutorialButton->setText(QCoreApplication::translate("a11Class", "DELETE  TUTORIAL BY TITLE", nullptr));
        deleteTutorialEdit->setText(QString());
        ignoreTutorialButton->setText(QCoreApplication::translate("a11Class", "IGNORE TUTORIAL", nullptr));
        likeTutorialButton->setText(QCoreApplication::translate("a11Class", "LIKE TUTORIAL", nullptr));
        label_11->setText(QCoreApplication::translate("a11Class", "SELECT A WATCHLIST FILE TYPE:", nullptr));
        CSV->setText(QCoreApplication::translate("a11Class", "CSV", nullptr));
        HTML->setText(QCoreApplication::translate("a11Class", "HTML", nullptr));
        label_12->setText(QCoreApplication::translate("a11Class", "DEFAULT: NO FILE PERSISTANCE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class a11Class: public Ui_a11Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A11_H
