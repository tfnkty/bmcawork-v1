/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../settings.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSettingsENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSettingsENDCLASS = QtMocHelpers::stringData(
    "Settings",
    "showEvent",
    "",
    "QShowEvent*",
    "event",
    "txtPresetTime_editingFinished",
    "txtPresetCounts_editingFinished",
    "txtDwellTime_editingFinished",
    "rbPHA_rbMCS_toggled",
    "rbPositive_rbNegative_toggled",
    "chkPresetTime_toggled",
    "chkPresetCounts_toggled",
    "chkBLR_toggled",
    "chkPUR_toggled",
    "chkHVON_toggled",
    "nmrMCSLLD_valueChanged",
    "nmrMCSULD_valueChanged",
    "nmrLLD_valueChanged",
    "nmrULD_valueChanged",
    "nmrPresetCountsLLD_valueChanged",
    "nmrPresetCountsULD_valueChanged",
    "nmrThreshold_valueChanged",
    "nmrVolt_valueChanged",
    "cmbPresetTime_currentIndexChanged",
    "cmbPHAChannels_currentIndexChanged",
    "cmbMCSChannels_currentIndexChanged",
    "cmbCoarseGain_currentIndexChanged",
    "cmbDigitalGain_currentIndexChanged",
    "cmbRT_currentIndexChanged",
    "cmbFT_currentIndexChanged",
    "cmbPZ_currentIndexChanged",
    "sldrFineGain_valueChanged",
    "cmdAdvanced_clicked",
    "cmdApply_clicked",
    "cmdStore_clicked",
    "cmdClose_clicked",
    "UpdateGUI",
    "MCASettings",
    "oSettings"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSettingsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  212,    2, 0x08,    1 /* Private */,
       5,    0,  215,    2, 0x08,    3 /* Private */,
       6,    0,  216,    2, 0x08,    4 /* Private */,
       7,    0,  217,    2, 0x08,    5 /* Private */,
       8,    1,  218,    2, 0x08,    6 /* Private */,
       9,    1,  221,    2, 0x08,    8 /* Private */,
      10,    1,  224,    2, 0x08,   10 /* Private */,
      11,    1,  227,    2, 0x08,   12 /* Private */,
      12,    1,  230,    2, 0x08,   14 /* Private */,
      13,    1,  233,    2, 0x08,   16 /* Private */,
      14,    1,  236,    2, 0x08,   18 /* Private */,
      15,    1,  239,    2, 0x08,   20 /* Private */,
      16,    1,  242,    2, 0x08,   22 /* Private */,
      17,    1,  245,    2, 0x08,   24 /* Private */,
      18,    1,  248,    2, 0x08,   26 /* Private */,
      19,    1,  251,    2, 0x08,   28 /* Private */,
      20,    1,  254,    2, 0x08,   30 /* Private */,
      21,    1,  257,    2, 0x08,   32 /* Private */,
      22,    1,  260,    2, 0x08,   34 /* Private */,
      23,    1,  263,    2, 0x08,   36 /* Private */,
      24,    1,  266,    2, 0x08,   38 /* Private */,
      25,    1,  269,    2, 0x08,   40 /* Private */,
      26,    1,  272,    2, 0x08,   42 /* Private */,
      27,    1,  275,    2, 0x08,   44 /* Private */,
      28,    1,  278,    2, 0x08,   46 /* Private */,
      29,    1,  281,    2, 0x08,   48 /* Private */,
      30,    1,  284,    2, 0x08,   50 /* Private */,
      31,    1,  287,    2, 0x08,   52 /* Private */,
      32,    0,  290,    2, 0x08,   54 /* Private */,
      33,    0,  291,    2, 0x08,   55 /* Private */,
      34,    0,  292,    2, 0x08,   56 /* Private */,
      35,    0,  293,    2, 0x08,   57 /* Private */,
      36,    1,  294,    2, 0x08,   58 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 37,   38,

       0        // eod
};

Q_CONSTINIT const QMetaObject Settings::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSSettingsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSettingsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSettingsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Settings, std::true_type>,
        // method 'showEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QShowEvent *, std::false_type>,
        // method 'txtPresetTime_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'txtPresetCounts_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'txtDwellTime_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rbPHA_rbMCS_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'rbPositive_rbNegative_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'chkPresetTime_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'chkPresetCounts_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'chkBLR_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'chkPUR_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'chkHVON_toggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'nmrMCSLLD_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'nmrMCSULD_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'nmrLLD_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'nmrULD_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'nmrPresetCountsLLD_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'nmrPresetCountsULD_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'nmrThreshold_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'nmrVolt_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const double, std::false_type>,
        // method 'cmbPresetTime_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'cmbPHAChannels_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'cmbMCSChannels_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'cmbCoarseGain_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'cmbDigitalGain_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'cmbRT_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'cmbFT_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'cmbPZ_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'sldrFineGain_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        // method 'cmdAdvanced_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cmdApply_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cmdStore_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cmdClose_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'UpdateGUI'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<MCASettings, std::false_type>
    >,
    nullptr
} };

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Settings *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showEvent((*reinterpret_cast< std::add_pointer_t<QShowEvent*>>(_a[1]))); break;
        case 1: _t->txtPresetTime_editingFinished(); break;
        case 2: _t->txtPresetCounts_editingFinished(); break;
        case 3: _t->txtDwellTime_editingFinished(); break;
        case 4: _t->rbPHA_rbMCS_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->rbPositive_rbNegative_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->chkPresetTime_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->chkPresetCounts_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->chkBLR_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->chkPUR_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->chkHVON_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->nmrMCSLLD_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->nmrMCSULD_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->nmrLLD_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->nmrULD_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->nmrPresetCountsLLD_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->nmrPresetCountsULD_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->nmrThreshold_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->nmrVolt_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 19: _t->cmbPresetTime_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->cmbPHAChannels_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->cmbMCSChannels_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->cmbCoarseGain_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->cmbDigitalGain_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->cmbRT_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->cmbFT_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->cmbPZ_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->sldrFineGain_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->cmdAdvanced_clicked(); break;
        case 29: _t->cmdApply_clicked(); break;
        case 30: _t->cmdStore_clicked(); break;
        case 31: _t->cmdClose_clicked(); break;
        case 32: { bool _r = _t->UpdateGUI((*reinterpret_cast< std::add_pointer_t<MCASettings>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSettingsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 33;
    }
    return _id;
}
QT_WARNING_POP
