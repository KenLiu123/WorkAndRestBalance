/********************************************************************************
** Form generated from reading UI file 'rest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REST_H
#define UI_REST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rest
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    QCheckBox *checkBox;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_3;
    QComboBox *restBox;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QComboBox *work_Box;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *rest)
    {
        if (rest->objectName().isEmpty())
            rest->setObjectName(QStringLiteral("rest"));
        rest->resize(350, 318);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rest->sizePolicy().hasHeightForWidth());
        rest->setSizePolicy(sizePolicy);
        rest->setMinimumSize(QSize(350, 318));
        rest->setMaximumSize(QSize(350, 318));
        QIcon icon;
        icon.addFile(QStringLiteral("assets/img/icon.svg"), QSize(), QIcon::Normal, QIcon::Off);
        rest->setWindowIcon(icon);
        rest->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        gridLayoutWidget = new QWidget(rest);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 351, 321));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(0, 25));

        horizontalLayout_4->addWidget(checkBox);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout_4, 8, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_6 = new QSpacerItem(90, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(12);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        restBox = new QComboBox(gridLayoutWidget);
        restBox->setObjectName(QStringLiteral("restBox"));
        restBox->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(restBox);

        horizontalSpacer_7 = new QSpacerItem(90, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(22);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(90, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        work_Box = new QComboBox(gridLayoutWidget);
        work_Box->setObjectName(QStringLiteral("work_Box"));
        work_Box->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(work_Box);

        horizontalSpacer_5 = new QSpacerItem(90, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer_2 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(80, 40));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 9, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 10, 0, 1, 1);


        retranslateUi(rest);

        QMetaObject::connectSlotsByName(rest);
    } // setupUi

    void retranslateUi(QWidget *rest)
    {
        rest->setWindowTitle(QApplication::translate("rest", "rest", Q_NULLPTR));
        checkBox->setText(QApplication::translate("rest", "\350\256\260\344\275\217\351\200\211\351\241\271", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("rest", "\350\256\276 \347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("rest", "\344\274\221\346\201\257\346\227\266\351\227\264", Q_NULLPTR));
        restBox->clear();
        restBox->insertItems(0, QStringList()
         << QApplication::translate("rest", "5\345\210\206\351\222\237", Q_NULLPTR)
         << QApplication::translate("rest", "10\345\210\206\351\222\237", Q_NULLPTR)
         << QApplication::translate("rest", "15\345\210\206\351\222\237", Q_NULLPTR)
         << QApplication::translate("rest", "20\345\210\206\351\222\237", Q_NULLPTR)
        );
        label->setText(QApplication::translate("rest", "\351\230\262\347\214\235\346\255\273\345\260\217\347\250\213\345\272\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("rest", "\345\267\245\344\275\234\346\227\266\351\227\264", Q_NULLPTR));
        work_Box->clear();
        work_Box->insertItems(0, QStringList()
         << QApplication::translate("rest", "0.5\345\260\217\346\227\266", Q_NULLPTR)
         << QApplication::translate("rest", "1\345\260\217\346\227\266", Q_NULLPTR)
         << QApplication::translate("rest", "1.5\345\260\217\346\227\266", Q_NULLPTR)
         << QApplication::translate("rest", "2\345\260\217\346\227\266", Q_NULLPTR)
         << QApplication::translate("rest", "2.5\345\260\217\346\227\266", Q_NULLPTR)
        );
        pushButton_2->setText(QApplication::translate("rest", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton->setText(QApplication::translate("rest", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rest: public Ui_rest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REST_H
