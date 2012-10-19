TEMPLATE = subdirs

CONFIG += ordered

shopping_mall.depends = common
wallclock.depends = common

SUBDIRS += \
    common \
    shopping_mall \
    wallclock

