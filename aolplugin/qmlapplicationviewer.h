// checksum 0x82ed version 0x60010
/*
  This file was generated by the Qt Quick Application wizard of Qt Creator.
  QmlApplicationViewer is a convenience class containing mobile device specific
  code such as screen orientation handling. Also QML paths and debugging are
  handled here.
  It is recommended not to modify this file, since newer versions of Qt Creator
  may offer an updated version of it.
*/

#ifndef QMLAPPLICATIONVIEWER_H
#define QMLAPPLICATIONVIEWER_H

#define XSERVICE "aol"

#include <QtDeclarative/QDeclarativeView>

#include <AccountSetup/ProviderPluginProcess>
#include <accounts-qt/Accounts/Account>
#include <accounts-qt/Accounts/Manager>

#include <telepathy-1.0/TelepathyQt4/Constants>
#include <telepathy-1.0/TelepathyQt4/AccountManager>
#include <telepathy-1.0/TelepathyQt4/PendingAccount>
#include <telepathy-1.0/TelepathyQt4/PendingOperation>
#include <telepathy-1.0/TelepathyQt4/PendingReady>
#include <telepathy-1.0/TelepathyQt4/PendingStringList>
#include <telepathy-1.0/TelepathyQt4/Account>
#include <telepathy-1.0/TelepathyQt4/AccountSet>

using namespace Tp;
using namespace Accounts;

class QmlApplicationViewer : public QDeclarativeView
{
    Q_OBJECT

public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit QmlApplicationViewer(QWidget *parent = 0);
    virtual ~QmlApplicationViewer();

    static QmlApplicationViewer *create();

    void setMainQmlFile(const QString &file);
    void addImportPath(const QString &path);

    // Note that this will only have an effect on Symbian and Fremantle.
    void setOrientation(ScreenOrientation orientation);

    void showExpanded();
    void init(int type);
    void desktopIcon(bool visible);

    Tp::AccountManagerPtr mAM;
    Tp::AccountPtr mAcc;
    Tp::AccountSetPtr mAccSet;

    QVariantList paramsSet;

    int initType;
    int accountId;
    WId parentWindowId;
    Accounts::Account *accountx;
    Accounts::Service *service;
    Accounts::Service *mainservice;
    Accounts::Manager *manager;

    bool dataUpdated;

    Q_INVOKABLE void createAccount(QVariant dname,
                                   QVariant uname,
                                   QVariant pword,
                                   QVariant dicon);
    Q_INVOKABLE void saveAccount(QString dname,
                                 QString uname,
                                 QString pword,
                                 QString server,
                                 QString port,
                                 QVariant encryption,
                                 QVariant dicon,
                                 QVariant aenabled);
    Q_INVOKABLE void deleteAccount();

private:
    explicit QmlApplicationViewer(QDeclarativeView *view, QWidget *parent);
    class QmlApplicationViewerPrivate *d;

private slots:
    // On Account Load operation
    void onReadyLoad(Tp::PendingOperation *op);
    // On Account save edited operations
    void onUpdateParameters(Tp::PendingOperation *op);
    void onDisplaynameChanged(Tp::PendingOperation *op);
    // On Account remove operations
    void onAccountRemoved(Tp::PendingOperation *op);
    void onAccountxRemoved();
    // On Create new Account operations
    void onAccountxCreated(Accounts::AccountId id);
    void onAccountCreated(Tp::PendingOperation *op);
    void onSynced();
};

QApplication *createApplication(int &argc, char **argv);

#endif // QMLAPPLICATIONVIEWER_H
