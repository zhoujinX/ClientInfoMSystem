#ifndef DLGITEM_H
#define DLGITEM_H

#include <QDialog>

namespace Ui {
class DlgItem;
}

typedef struct _Customer{
    QString name;       //单位名称
    int type;           //单位类型[企业，高校，研究所，...]
    int area;           //区域[华东，华南，华中，...],下拉框
    int province;       //省份（华东：[山东，浙江，...]）,下拉框
    QString city;       //城市
    QString address;    //地址
    QString site;       //网址
    QString contact;    //联系方式
    QString buy;        //采购情况
    QString research;   //研究方向
    QString remark;     //备注
}Customer,*PCustomer;

class DlgItem : public QDialog
{
    Q_OBJECT

public:
    explicit DlgItem(Customer* item,QWidget *parent = 0);
    ~DlgItem();

signals:
    void sigAddItem(Customer*);

private slots:
    void on_btnAdd_clicked();       //“增加”按钮动作
    void on_btnCancel_clicked();    //“取消”按钮取消动作
    void on_combo2_currentTextChanged(const QString &arg1); //combo2:area，区域改变，跟着省份也会改变
    void on_edit1_textChanged(const QString &arg1);

private:
    int String2Province(QString s);
    QString Province2String(int province);

private:
    Ui::DlgItem *ui;
    Customer* mItem;
};

#endif // DLGITEM_H
