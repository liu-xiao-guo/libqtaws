/*
    Copyright 2013-2016 Paul Colby

    This file is part of libqtaws.

    Libqtaws is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Libqtaws is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with libqtaws.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QTAWS_SSMCLIENT_P_H
#define QTAWS_SSMCLIENT_P_H

#include "core/awsabstractclient_p.h"

class QNetworkAccessManager;

QTAWS_BEGIN_NAMESPACE

class SsmClient;

class QTAWS_EXPORT SsmClientPrivate : public AwsAbstractClientPrivate {

public:
    SsmClientPrivate(SsmClient * const q);

private:
    Q_DECLARE_PUBLIC(SsmClient)
    Q_DISABLE_COPY(SsmClientPrivate)

};

QTAWS_END_NAMESPACE

#endif