#include "UnsyncGenerator.h"

#include <QUuid>

#include "../../Game.h"

using namespace kv;

UnsyncGenerator::UnsyncGenerator()
{
    unsync_string_ = "default";
}

void UnsyncGenerator::PerformUnsync()
{
    qDebug() << "Unsync will be performed";
    unsync_string_ = QUuid::createUuid().toString();
}
