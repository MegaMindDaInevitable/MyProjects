
#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H


#include <QObject>
#include <QWidget>

class QComboBox;
class QPushButton;
class QLineEdit;
class QTextEdit;
class QMetaEnum;
class QString;
class QDate;
class Staffmember : public QWidget
{
    Q_OBJECT
    //Q_PROPERTY(QDate birthDate READ birthDate WRITE setDate NOTIFY getDate)
    //Q_PROPERTY(QString my_name READ name WRITE setName NOTIFY getName)

public:
    explicit Staffmember(QWidget *parent = nullptr);
    enum AppointmentType
    {
        Permanent,
        Contract,
        Parttime
    };
    Q_ENUM(AppointmentType)

    QString name() const;
    //void setName(QString newName);
    QDate birthDate() const;
    AppointmentType appointment() const;
    ;
signals:
    //void getName(QString newName);
   // void getDate(QDate newDate);

private slots:

    void processInput();


private:

    void GuiSet();

    QComboBox *combo;

    QLineEdit *inputName;
    QLineEdit *inputBirthdate;
    QLineEdit *staffAppointmentType;

    QTextEdit *nameInputSpace;
    QTextEdit *brthDateSpace;
    QTextEdit *staffAppointmentTypeSpc;
    QTextEdit *infoDisplay;

    QPushButton *addInfo;
    QPushButton *printInfo;

    QString my_name;
    AppointmentType my_appointment;
};

#endif // STAFFMEMBER_H
