/********************************************************************************
** Form generated from reading UI file 'exercise.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXERCISE_H
#define UI_EXERCISE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exercise
{
public:
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *text_label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *exercise)
    {
        if (exercise->objectName().isEmpty())
            exercise->setObjectName(QStringLiteral("exercise"));
        exercise->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exercise->sizePolicy().hasHeightForWidth());
        exercise->setSizePolicy(sizePolicy);
        exercise->setMinimumSize(QSize(1920, 1080));
        exercise->setMaximumSize(QSize(1920, 1080));
        verticalWidget = new QWidget(exercise);
        verticalWidget->setObjectName(QStringLiteral("verticalWidget"));
        verticalWidget->setGeometry(QRect(0, 0, 1920, 1080));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy1);
        verticalWidget->setMinimumSize(QSize(1920, 1080));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        text_label = new QLabel(verticalWidget);
        text_label->setObjectName(QStringLiteral("text_label"));
        text_label->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(text_label->sizePolicy().hasHeightForWidth());
        text_label->setSizePolicy(sizePolicy2);
        text_label->setMinimumSize(QSize(0, 80));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        text_label->setFont(font);
        text_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(text_label);

        groupBox = new QGroupBox(verticalWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);


        verticalLayout->addWidget(groupBox);


        retranslateUi(exercise);

        QMetaObject::connectSlotsByName(exercise);
    } // setupUi

    void retranslateUi(QWidget *exercise)
    {
        exercise->setWindowTitle(QApplication::translate("exercise", "\344\274\221\346\201\257\344\270\200\344\270\213", Q_NULLPTR));
        text_label->setText(QApplication::translate("exercise", "Press Esc to End the Rest ", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("exercise", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("exercise", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("exercise", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class exercise: public Ui_exercise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXERCISE_H
