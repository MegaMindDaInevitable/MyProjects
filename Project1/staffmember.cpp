#include "staffmember.h"

#include<QMetaObject>
#include<QComboBox>
#include<QLineEdit>
#include<QTextEdit>
#include<QPushbutton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QTextStream>
#include<QMetaEnum>
#include<QLabel>
#include <QFile>
#include<QDate>

Staffmember::Staffmember(QWidget *parent)
    : QWidget{parent},inputName(new QLineEdit),
    inputBirthdate(new QLineEdit),
    staffAppointmentType(new QLineEdit),
    nameInputSpace(new QTextEdit),
    brthDateSpace(new QTextEdit),
    staffAppointmentTypeSpc(new QTextEdit),
    addInfo(new QPushButton("Add Infomation To List")),
    printInfo(new QPushButton("Print Information To Text File"))
{

    GuiSet();
    setWindowTitle("Assignmnet1 Question1");
    setMinimumSize(250, 300);



    connect(addInfo, &QPushButton::clicked,this , &Staffmember::processInput);


}

QString Staffmember::name() const
{
    return my_name;
}

/*QDate Staffmember::birthDate() const
{
    //return my_birthdate;
}*/

Staffmember::AppointmentType Staffmember::appointment() const
{
    return my_appointment;
}

void Staffmember::processInput()
{

    nameInputSpace->append(inputName->text());
    nameInputSpace->append(inputBirthdate->text());
    nameInputSpace->append(staffAppointmentType->text());

    inputName->clear();
    inputName->setFocus();
    inputBirthdate->clear();
    inputBirthdate->setFocus();
    staffAppointmentType->clear();
    staffAppointmentType->setAlignment(Qt::AlignHCenter);

}

void Staffmember::GuiSet()
{

    /*QVBoxLayout *layoutName(new QVBoxLayout(this));
    QVBoxLayout *layoutBirth(new QVBoxLayout(this));
    QVBoxLayout *layoutStaffAppoint(new QVBoxLayout(this));*/
    QVBoxLayout *layout(new QVBoxLayout(this));

    QLabel *namelbl(new QLabel("Enter Name"));
    QLabel *birthDatelbl(new QLabel("Enter Birth Date"));
    QLabel *appointmentInput(new QLabel("Enter  Appointment type"));
    QLabel *showInfo(new QLabel("Information Display"));

    QComboBox *combo(new QComboBox(this));

    const QMetaObject *metaObject = this->metaObject();
    int enumIndex = metaObject->indexOfEnumerator("AppointmentType");
    QMetaEnum metaEnum = metaObject->enumerator(enumIndex);


    for(int i = 0; i <metaEnum.keyCount();i++)
    {
        const char *key = metaEnum.key(i);
        int value = metaEnum.value(i);
        combo->addItem(key, value);
    }



    layout->addWidget(namelbl);
    layout->addWidget(inputName);

    layout->addWidget(birthDatelbl);
    layout->addWidget(inputBirthdate);

    layout->addWidget(appointmentInput);
    layout->addWidget(combo);

    layout->addWidget(showInfo);
    layout->addWidget(nameInputSpace);


    layout->addWidget(addInfo);
    layout->addWidget(printInfo);

    setLayout(layout);


}



